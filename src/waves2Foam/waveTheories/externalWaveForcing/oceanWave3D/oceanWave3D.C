/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright held by original author
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM; if not, write to the Free Software Foundation,
    Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

\*---------------------------------------------------------------------------*/

#include "oceanWave3D.H"
#include "addToRunTimeSelectionTable.H"

#include "fvCFD.H"
#include "uniformDimensionedFields.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

extern "C" double __globalvariables_MOD_time;
extern "C" double __globalvariables_MOD_dt;
extern "C" int __globalvariables_MOD_tstep;
extern "C" int __globalvariables_MOD_ic;
extern "C" int __globalvariables_MOD_nsteps;
extern "C" int __globalvariables_MOD_nofpoints;
extern "C" double* __globalvariables_MOD_xofpoints;
extern "C" double* __globalvariables_MOD_yofpoints;
extern "C" double* __globalvariables_MOD_eof;
extern "C" double* __globalvariables_MOD_uxof;
extern "C" double* __globalvariables_MOD_uyof;
extern "C" double* __globalvariables_MOD_uzof;
extern "C" void oceanwave3dt0setup_();
extern "C" void oceanwave3dtakeatimestep_();
extern "C" void closeiofiles_();
extern "C" void closevariables_();
extern "C" void interpolationinitialize_();
extern "C" void calculatekinematics_();
extern "C" void openfoaminterface_eta_(double(*)[3] , double *);
extern "C" void openfoaminterface_u_(double(*)[3] , double *, double *, double *);
extern "C" void writeoceanwave3d_(int *);
extern "C" void preprocessofdomains_(const int *,const int *, double*,const  int *,const  int(*), double*,const  double *,const  int *,const  int *,const  int *,const  int *,const  int(*),const  int(*), double*);
extern "C" void preprocessofpoints_();
extern "C" void writeoftoocw3d_eta_();
extern "C" void writeoftoocw3d_eta_ux_uy_();
extern "C" void writeoftoocw3d_eta_w_();
extern "C" void writeoftoocw3d_fully_();

namespace waveTheories
{

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

defineTypeNameAndDebug(oceanWave3D, 0);

addToRunTimeSelectionTable
(
    externalWaveForcing,
    oceanWave3D,
    externalWaveForcing
);

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //


oceanWave3D::oceanWave3D
(
    IOobject io,
    Time& rT,
    const fvMesh& mesh
)
:
    externalWaveForcing(io, rT, mesh),

    waveProps_(io.db().lookupObject<IOdictionary>("waveProperties")),
    coeffDict_(waveProps_.subDict("externalForcingCoeffs")),

    seaLevel_(readScalar(waveProps_.lookup("seaLevel"))),

    N_(readLabel(coeffDict_.lookup("nIntervals"))),

    startTimes_("startTimes", coeffDict_, N_),

    endTimes_("endTimes", coeffDict_, N_),

    ramp_(Switch(coeffDict_.lookup("rampInterval"))),

    Tsoft_(0),

    translateOFMesh_
    (
    	coeffDict_.lookup("translateOpenFoamMesh")
//    	coeffDict_.lookupOrDefault<vector>
//        (
//        	"translateOpenFoamMesh", vector::zero
//        )
    ),

    OFtoOCW_(tensor::zero),

    OCWtoOF_(tensor::zero),
    
    //JK:
    OfPoints_(0),
    
    indVertCoord_(-GREAT),
    
    couplingType_(coeffDict_.lookup("couplingType"))
{
	if (N_ > 1)
	{
		FatalErrorIn("oceanWave3D::oceanWave3D(IOobject io, Time& rT, const fvMesh& mesh)")
			<< "Unwanted behaviour has been observed in the re-starting, when\n"
			<< "multiple intervals are used. Consequently, make one simulation"
			<< "per interval instead.\n"
			<< endl << exit(FatalError);
	}

	// Initialise to the first set of intervals
    startTime_ = -GREAT;
    endTime_ = GREAT;

    forAll (startTimes_, timei)
    {
    	if (rT_.time().value() < endTimes_[timei])
    	{
    		startTime_ = startTimes_[timei];
    		endTime_ = endTimes_[timei];
    		N_ = timei;
    		break;
    	}
    }

    if (rT_.endTime().value() < startTime_)
    {
		FatalErrorIn("oceanWave3D::oceanWave3D(IOobject io, Time& rT, const fvMesh& mesh)")
			<< "The simulation will terminate before the selected interval starts.\n"
			<< "Correct the endTime in system/controlDict.\n"
			<< endl << exit(FatalError);
    }

    if (rT_.endTime().value() < endTime_)
    {
		FatalErrorIn("oceanWave3D::oceanWave3D(IOobject io, Time& rT, const fvMesh& mesh)")
			<< "The simulation will terminate before the selected interval ends.\n"
			<< "Correct the endTime in system/controlDict.\n"
			<< endl << exit(FatalError);
    }

	if (ramp_)
	{
		Tsoft_ = readScalar(coeffDict_.lookup("Tsoft"));
	}

	// Make the mapping tensors
	mappingTensors();
	
	if (Pstream::master())
	{
		// Start OceanWave3D (only master)
		oceanwave3dt0setup_();
		
		
		// JK: Initialize 2-way coupling (only master)
		setUpTwoWayCoupling();
		
		
		// Initialise the interpolation routine (only master)
		interpolationinitialize_();

		// Get the uniform time step specified in OceanWave3D input file (only master)
		maxDT_ = __globalvariables_MOD_dt;

		label ocwDuration = __globalvariables_MOD_nsteps;

		if (maxDT_*ocwDuration < rT_.endTime().value())
		{
			FatalErrorIn("oceanWave3D::oceanWave3D(IOobject io, Time& rT, const fvMesh& mesh)")
				<< "The duration of the OpenFoam simulation ("
				<< rT_.endTime().value() << " s) exceeds the duration of the \n"
				<< "OceanWave3D simulation (" << maxDT_*ocwDuration << " s).\n"
				<< exit(FatalError) << endl << endl;
		}
		
		// Update the OceanWave3D to current time (restart) (only master)
		alignTimes();
	}
	
	//JK: set up Probes to sample OpenFOAM solution
	setUpSampling();

}

// * * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * //

scalar oceanWave3D::factor(const scalar& time) const
{
    scalar factor(1.0);

    scalar rampTime = time;

    if (ramp_)
    {
        rampTime -= startTime_;
    }

    if (0.0 < Tsoft_)
    {
     	factor = Foam::sin(2*M_PI/(4.0*Tsoft_)*Foam::min(Tsoft_, rampTime));
    }

    return factor;
}


dimensionedScalar oceanWave3D::OCWTimeStep() const
{
    return dimensionedScalar
    	(
    		"null",
    		dimTime,
    		Foam::min(1.2*rT_.deltaT().value(), maxDT_)
        );
}


void oceanWave3D::mappingTensors()
{
	// Get a unit vector along the direction of gravity.
	vector g = uniformDimensionedVectorField
        (
	        mesh_.thisDb().lookupObject<uniformDimensionedVectorField>("g")
	    ).value();

	g = cmptMultiply(g, g);
	g /= Foam::mag(g);

	// Discard a gravity vector pointing partyly in the X-direction
	if ((g & vector(1, 0, 0)) < SMALL)
	{
		// M_11 = 1;
        OFtoOCW_.xx() = 1;

        // Set the remaining coefficients of M depending on the direction of
        // gravity.
        if (SMALL < (g & vector(0, 1, 0)))
        {
        	OFtoOCW_.zy() = 1;
        	OFtoOCW_.yz() = 1;
        	//JK: y is the vertical coordinate
        	indVertCoord_ = 1;
        }
        else
        {
        	OFtoOCW_.yy() = 1;
        	OFtoOCW_.zz() = 1;
        	//JK: z is the vertical coordinate
        	indVertCoord_ = 2;
        }
	}
	else
	{
		FatalErrorIn("void oceanWave3D::mappingTensors()")
			<< "The gravity points (partly) in the x-direction. This is not \n"
			<< "supported together with the oceanWave3D external forcing class."
			<< endl << exit(FatalError);
	}

	// Create the inverse map
	OCWtoOF_ = Foam::inv(OFtoOCW_);

	// Check that the translation vector is horizontal
    if (SMALL < Foam::mag(translateOFMesh_ & g))
    {
    	FatalErrorIn("void oceanWave3D::mappingTensors()")
    	    << "The translation vector of the computational mesh for OpenFoam\n"
    		<< "is not horizontal. "
    		<< endl << exit(FatalError);
    }
}


void oceanWave3D::updateIntervals()
{
	// Update the start-end times, if there are any intervals left. Otherwise,
	// set the start time and end times to a very, very big number.
	if (endTime_ < rT_.time().value())
	{
        N_++;

		if (N_ < startTimes_.size())
		{
		    startTime_ = startTimes_[N_];
		    endTime_ = endTimes_[N_];
		}
		else
		{
			startTime_ = GREAT;
			endTime_ = GREAT;
		}
	}
}


void oceanWave3D::alignTimes()
{
	Info << "OF-time: " << rT_.time().value() << endl;
	Info << "OCW-time: " << __globalvariables_MOD_time << endl;
    Info << "Interval: [" << startTime_ << ", " << endTime_ << "]" << endl;

    // If the starting times are identical, simply do nothing
    if (Foam::mag(rT_.time().value() - __globalvariables_MOD_time) < 1.0e-9)
    {
    	Info << "Identical starting times for OceanWave3D and OpenFoam" << endl;

    	return;
    }

    // If the OpenFoam starting time exceeds that of OceanWave3D, take a number
    // of OceanWave3D steps.
    if (__globalvariables_MOD_time < rT_.time().value())
    {
    	// Evaluate the mismatch in start time
    	scalar dT = rT_.time().value() - __globalvariables_MOD_time;

    	// Calculate the number of OceanWave3D time steps and the time step
        label NtimeSteps = std::ceil(dT/maxDT_);
        scalar alignDt = dT/NtimeSteps;

        // Loop OceanWave3D
        for (long n=0; n < NtimeSteps; n++)
        {
            takeTimeStep(alignDt, false);
        }

        // Calculate the kinematics, which could be needed for setWaveField at
        // at a mapping time larger than 0
        calculateKinematics();

        // Chech again for the alignment of the times.
        alignTimes();
    }
    else
    {
    	FatalErrorIn("void oceanWave3D::alignTimes()")
    			<< "The starting time in OceanWave3D exceeds the starting time\n"
    			<< "in OpenFoam: \n\n"
    			<< "Start time in OceanWave3D: " << __globalvariables_MOD_time << " s.\n"
    			<< "Start time in OpenFoam:    " << rT_.time().value() << " s."
    			<< endl << exit(FatalError);
    }
}


void oceanWave3D::timeStepOceanWave3D()
{
    // If the current time is less than the next startTime_ for OpenFoam,
	// perform a lot of time steps with OceanWave3D, map the solution and
	// go back to OpenFoam
	if (rT_.time().value() < startTime_)
	{
		// Make sure to take the one time step that the time in OpenFoam has
		// already been increased with:
		takeTimeStep(rT_.deltaT().value(), false);

	    while (SMALL < startTime_ - rT_.time().value())
	    {
	    	// Set the size of the time step
	    	dimensionedScalar dt = OCWTimeStep();

	    	// Go forward in time
		    rT_.setDeltaT(dt);
            rT_++;

            Info << this->type() << ": Time = " << rT_.time().value() << " s.\n"
                 << this->type() << ": deltaT = " << rT_.deltaT().value() << " s."
                 << endl << endl;

            // Take a time step with OpenFoam 3D
            takeTimeStep(false);

            // Make sure that the model ends, if the endTime of the OpenFoam
            // simulation is exceeded. Instead of going back to OpenFoam and do
            // one more time step, a simple 'FatalErrorIn' approach has been
            // used. It is not pretty, but it works.
            if (rT_.endTime().value() < rT_.time().value())
            {
            	FatalErrorIn("void oceanWave3D::step()")
            		<< "This is not a FatalError, but it is a simple way to stop"
            		<< " the execution. " << exit(FatalError);
            }
	    }

	    // Calculate the kinematics from the last time step
	    calculateKinematics();

	    // Map the solution to the OF-domain
        mapSolution();

        updatePhi();

        updateTimeAndTimeStep();
	}
}


void oceanWave3D::mapSolution()
{
	// Obtain references to the various field. Note the const_case!
    volScalarField& rho = const_cast<volScalarField&>
        (
        	mesh_.thisDb().lookupObject<volScalarField>("rho")
        );

    volScalarField& alpha = const_cast<volScalarField&>
        (
           	mesh_.thisDb().lookupObject<volScalarField>
            (
                Foam::waves2Foam::aName()
            )
        );

    volScalarField& pd = const_cast<volScalarField&>
        (
           	mesh_.thisDb().lookupObject<volScalarField>
            (
                Foam::waves2Foam::pName()
            )
        );

    volVectorField& U = const_cast<volVectorField&>
        (
           	mesh_.thisDb().lookupObject<volVectorField>
            (
                "U"
            )
        );

    // Map the solution using the setWaveField functionality
    Info << "Mapping the OceanWave3D solution to the OpenFoam domain" << endl;
    Info << "Applied ramping factor: " << factor(rT_.time().value()) << endl;
    Info << endl;

    word name(coeffDict_.lookup("mappingZone"));
    setWaveField mapSolution(mesh_, name, U, alpha, pd);

    mapSolution.correct();

    U.correctBoundaryConditions();
    alpha.correctBoundaryConditions();
    pd.correctBoundaryConditions();

    // Obtain the densities
    const dictionary& dict
        = mesh_.thisDb().lookupObject<IOdictionary>("transportProperties");

    dimensionedScalar rho0(dict.subDict(waves2Foam::airPhase()).lookup("rho"));
    dimensionedScalar rho1(dict.subDict(waves2Foam::waterPhase()).lookup("rho"));

    // Update the density based on the mapped alpha-field
    rho = (alpha*rho1 + (1 - alpha)*rho0);
    rho.correctBoundaryConditions();
}


void oceanWave3D::updatePhi()
{
	// Obtain references to the phi field. Note the const_case!
	surfaceScalarField& phi = const_cast<surfaceScalarField&>
	    (
	      	mesh_.thisDb().lookupObject<surfaceScalarField>("phi")
	    );

    const volScalarField& pd =
    	mesh_.thisDb().lookupObject<volScalarField>
        (
            Foam::waves2Foam::pName()
        );

    const volScalarField& rho =
    	mesh_.thisDb().lookupObject<volScalarField>
        (
            "rho"
        );

    const volVectorField& U = mesh_.thisDb().lookupObject<volVectorField>("U");

    surfaceScalarField phiTemp
    (
        IOobject
        (
            "phiTemp",
            rT_.timeName(),
            mesh_,
            IOobject::NO_READ,
            IOobject::NO_WRITE
        ),
        linearInterpolate(U) & mesh_.Sf()
    );


    // Map the phiTemp -> phi
#if EXTBRANCH==1
    phi.internalField() = phiTemp.internalField();
#elif OFPLUSBRANCH==1
    #if OFVERSION<1706
        phi.internalField() = phiTemp.internalField();
    #else
        phi.ref() = phiTemp.internalField();
    #endif
#else
    #if OFVERSION<400
        phi.internalField() = phiTemp.internalField();
    #else
        phi.ref() = phiTemp.internalField();
    #endif
#endif
    

    forAll (phi.boundaryField(), patchi)
    {
#if OFPLUSBRANCH==1
    #if OFVERSION<1706
    	phi.boundaryField()[patchi] == phiTemp.boundaryField()[patchi];
    #else
    	phi.boundaryFieldRef()[patchi] == phiTemp.boundaryField()[patchi];
    #endif
#else
	//JK: comment this line for use with OF4.1
  	//phi.boundaryField()[patchi] == phiTemp.boundaryField()[patchi];
#endif
    }

    // Perform the correction to phi utilising the correctPhi code (foam-extend-3.1)
    {
    	// Get the controls
    	dictionary pimple = mesh_.solutionDict().subDict("PIMPLE");

 	    int nNonOrthCorr =
   	        pimple.lookupOrDefault<int>("nNonOrthogonalCorrectors", 0);

 	    // Get information on the reference pressure
 	    label pdRefCell = 0;
 	    scalar pdRefValue = 0.0;

 	    if (pd.needReference())
 	    {
            pdRefCell = readLabel(pimple.lookup("pdRefCell"));
            pdRefValue = readScalar(pimple.lookup("pdRefValue"));
 	    }

 	    // Set up the correction of phi
        wordList pcorrTypes
        (
            pd.boundaryField().size(),
            zeroGradientFvPatchScalarField::typeName
        );

        for (label i=0; i<pd.boundaryField().size(); i++)
        {
            if (pd.boundaryField()[i].fixesValue())
            {
                pcorrTypes[i] = fixedValueFvPatchScalarField::typeName;
            }
        }

        volScalarField pcorr
        (
            IOobject
            (
                "pcorr",
                rT_.timeName(),
                mesh_,
                IOobject::NO_READ,
                IOobject::NO_WRITE
            ),
            mesh_,
            dimensionedScalar("pcorr", pd.dimensions(), 0.0),
            pcorrTypes
        );

        dimensionedScalar rUAf("(1|A(U))", dimTime/rho.dimensions(), 1.0);

        adjustPhi(phi, U, pcorr);

        for(int nonOrth=0; nonOrth<=nNonOrthCorr; nonOrth++)
        {
            fvScalarMatrix pcorrEqn
            (
                fvm::laplacian(rUAf, pcorr) == fvc::div(phi)
            );

            pcorrEqn.setReference(pdRefCell, pdRefValue);
            pcorrEqn.solve();

            if (nonOrth == nNonOrthCorr)
            {
            	phi -= pcorrEqn.flux();
            }
        }
    }

    // Write the mapped field
    U.write();
    pd.write();
    rho.write();
    mesh_.thisDb().lookupObject<volScalarField>(waves2Foam::aName()).write();
}


void oceanWave3D::updateTimeAndTimeStep()
{
	// Make constant references to change the names of local variables to fit
	// with the standard approaches
	const fvMesh& mesh = mesh_;
	const surfaceScalarField& phi
	    = mesh_.thisDb().lookupObject<surfaceScalarField>("phi");

	// Make name-change to rT_. Has to be a non-const, because setDeltaT.H
	// modifies the time step
	Time& runTime = rT_;

	// Calculate the Courant number
    #include "CourantNo.H"

	// Set the time step according to the new phi-field
#if EXTBRANCH==1
    #if OFVERSION<400
	#include "readTimeControls.H"
    #else
        #include "createTimeControls.H"   
    #endif
#elif OFPLUSBRANCH==1
    #include "createTimeControls.H"
#else
    #if OFVERSION<300
        #include "readTimeControls.H"
    #else
        #include "createTimeControls.H"
    #endif
#endif
    #include "setDeltaT.H"

	//JK: set deltaT back to fixed timestep if not adjustable
	if (! adjustTimeStep)
	{
		runTime.setDeltaT( readScalar(runTime.controlDict().lookup("deltaT")) );
	}
	
	// Update time:
	runTime++;
}


void oceanWave3D::takeTimeStep(bool calcKinematics)
{
	takeTimeStep(rT_.deltaT().value(), calcKinematics);
}


void oceanWave3D::takeTimeStep(const scalar dt, bool calcKinematics)
{

	// Set the time step for OceanWave3D and increase its time step counter
    __globalvariables_MOD_dt = dt;
    __globalvariables_MOD_tstep = __globalvariables_MOD_tstep + 1;

    // Take one time step in OceanWave3D
    oceanwave3dtakeatimestep_();

    // If required, calculate the wave kinematics in OceanWave3D
    if (calcKinematics)
    {
    	calculateKinematics();
    }
}


void oceanWave3D::calculateKinematics()
{
	calculatekinematics_();
}


void oceanWave3D::writeExternal() const
{
	// Create the output directory, if it does not exist
	fileName outputDir = rT_.path();

	if (Pstream::parRun())
	{
		outputDir = rT_.path()/"../OCW3Dhotstart/";
	}
	else
	{
		outputDir = rT_.path()/"OCW3Dhotstart/";
	}

	if (!Foam::isDir(outputDir))
	{
		Foam::mkDir(outputDir);
	}

    // Write the OCW3D data, if the current time is an output time and the
	// running process is the master node
	if (Pstream::master() && rT_.outputTime())
    {
        // The index of the written field is based on the timeIndex in OpenFoam
		// Consequently, it is easy to match a hot-start file for OCW3D with
		// OpenFoam, because the time index is written in <time>/uniform/time
    	int writeCounter = rT_.timeIndex();

    	// Write the data
    	writeoceanwave3d_(&writeCounter);
    }
}

//JK: read two way coupling input from dict and pass to OceanWave3D
void oceanWave3D::setUpTwoWayCoupling()
{
	
	wordList domainNames=coeffDict_.lookup("domainNames");
	const int nDomains = domainNames.size();
	int nRelax = 0;
	int nStruc = 0;
	int _RorC[nDomains]; //1 means rectangular, 2 means circular Domain
	double _BBoxD[nDomains*4];
	
	// loop trough domains, count relaxation zones and set up the domains bounding box
	forAll (domainNames, domaini)
	{
		dictionary sd( coeffDict_.subDict(domainNames[domaini] + "Coeffs"));
		wordList relaxationNames=sd.lookup("relaxationNames");
		nRelax = nRelax + relaxationNames.size();
		
		wordList structureNames=sd.lookup("structureNames"); //JKTODO lookupordefault
		nStruc = nStruc + structureNames.size();
		
		word domainShape(sd.lookup("domainShape"));
		if (domainShape == "Rectangular")
		{
			_RorC[domaini]=1;
			
			point startX(sd.lookup("startX"));
			point endX(sd.lookup("endX"));
			
			startX = OFtoOCW_ & (startX + translateOFMesh_);
			endX = OFtoOCW_ & (endX + translateOFMesh_);
			
			_BBoxD[domaini*4] = Foam::min(startX[0], endX[0]);
			_BBoxD[domaini*4 + 1] = Foam::max(startX[0], endX[0]);
			_BBoxD[domaini*4+2] = Foam::min(startX[1], endX[1]);
			_BBoxD[domaini*4 + 3] = Foam::max(startX[1], endX[1]);					
			
		}
		else if (domainShape == "Cylindrical")
		{
			_RorC[domaini]=2;
			
			point centre(sd.lookup("centre"));
			double radius(readScalar(sd.lookup("radius")));
			
			centre = OFtoOCW_ & (centre + translateOFMesh_);
			
			_BBoxD[domaini*4] = centre[0];
			_BBoxD[domaini*4 + 1] = centre[1];
			_BBoxD[domaini*4+2] = radius;
			_BBoxD[domaini*4 + 3] = 0;	
		}
		else
		{
			FatalErrorIn("oceanWave3D::setUpTwoWayCoupling()")
			<< "domainShape " << domainShape << " unknown." 
			<< "domainShape must be Rectangular or Cylindrical"
			<< exit(FatalError) << endl << endl;
		}
	}
	
	
	int _domainNr[nRelax];
	double _BBoxR[nRelax * 4];
	double _param[nRelax];
	int _dir[nRelax];
	int _ftype[nRelax];
	int _XorYorC[nRelax]; //1 means X, 2 means Y, 3 means Circular
	int _domainNrS[nStruc];
	int _RorCS[nStruc]; //1 means rectangular, 2 means circular Domain
	double _BBoxS[nStruc * 4];
	
	// global index for relaxation zone and structures
	label indRelax(0);
	label indStruc(0);
	
	// loop trough relaxation zones and set up the bounding box, domainNr and direction 
	forAll (domainNames, domaini)
	{
		dictionary sd( coeffDict_.subDict(domainNames[domaini] + "Coeffs"));
		wordList relaxationNames=sd.lookup("relaxationNames");
		
		//set up corrisponding relaxation zones
		forAll (relaxationNames, relaxi)
		{
			_domainNr[indRelax] = domaini+1; //domaini starts at 0 while the fist domainis Nr1
			_param[indRelax] = readScalar(coeffDict_.lookup("OCWrelaxationParam"));
			_ftype[indRelax] = readInt(coeffDict_.lookup("OCWrelaxationFuction"));
			
			dictionary rl( waveProps_.subDict(relaxationNames[relaxi] + "Coeffs").subDict("relaxationZone"));
			
		
			word relaxationShape(rl.lookup("relaxationShape"));
			if (relaxationShape == "Rectangular")
			{
				
				// get relaxation zone bounding box
				point startX(rl.lookup("startX"));
				point endX(rl.lookup("endX"));
				
				startX = OFtoOCW_ & (startX + translateOFMesh_);
				endX = OFtoOCW_ & (endX + translateOFMesh_);
				
				_BBoxR[indRelax*4] = Foam::min(startX[0], endX[0]);
				_BBoxR[indRelax*4 + 1] = Foam::max(startX[0], endX[0]);
				_BBoxR[indRelax*4+2] = Foam::min(startX[1], endX[1]);
				_BBoxR[indRelax*4 + 3] = Foam::max(startX[1], endX[1]);
				
				// get orientation of relaxation zone
				vector orientation(rl.lookup("orientation"));
				// rotate vector in case of OUTLET
				word relaxType(rl.lookup("relaxType"));
				word Outlet("OUTLET");
				if (relaxType == Outlet)
					{
						orientation = - orientation;
					}
				orientation = OFtoOCW_ & orientation;
				
				if ( abs(orientation[1] + orientation[2]) < SMALL)
				{
					// x-direction
					_XorYorC[indRelax]=1;
					if ( orientation[0] > 0) { _dir[indRelax]= -1; }
					else { _dir[indRelax]= 1; }
				}
				else if ( abs(orientation[0] + orientation[2]) < SMALL)				
				{
					// y-direction
					_XorYorC[indRelax]=2;
					if ( orientation[1] > 0) { _dir[indRelax]= -1; }
					else { _dir[indRelax]= 1; }
				}
				else
				{
					FatalErrorIn("oceanWave3D::setUpTwoWayCoupling()") 
					<<" relaxation zones must be oriented in OceanWave3D's x- or y-direction" 
					<< exit(FatalError) << endl << endl;
				}
				//flip direction in case of Allans sponge filter
				if (_ftype[indRelax]==9) { _dir[indRelax] = -_dir[indRelax];}
			}
			else if (relaxationShape == "Cylindrical")
			{
				_XorYorC[indRelax]=3;
				_dir[indRelax]= 1;
				
				point centre(rl.lookup("centre"));
				double rInner(readScalar(rl.lookup("rInner")));
				double rOuter(readScalar(rl.lookup("rOuter")));
				
				centre = OFtoOCW_ & (centre + translateOFMesh_);
				
				_BBoxR[indRelax*4] = centre[0];
				_BBoxR[indRelax*4 + 1] = centre[1];
				_BBoxR[indRelax*4 + 2] = rInner;
				_BBoxR[indRelax*4 + 3] = rOuter;	
			}
			else
			{
				FatalErrorIn("oceanWave3D::setUpTwoWayCoupling()")
				<< "relaxationShape " << relaxationShape << nl 
				<<" is not implemented for coupling to OceanWave3D." 
				<< "relaxationShape must be Rectangular or Cylindrical"
				<< exit(FatalError) << endl << endl;
			}	
			
			// increase global relaxation zone index
			indRelax++;
		}
		
		
		
		//set up corrisponding structures
		wordList structureNames=sd.lookup("structureNames"); //JKTODO lookupordefault
		forAll (structureNames, structi)
		{
			_domainNrS[indStruc] = domaini+1; //domaini starts at 0 while the fist domainis Nr1
			
			dictionary ssd( sd.subDict(structureNames[structi] + "Coeffs"));
			
		
			word structureShape(ssd.lookup("structureShape"));
			if (structureShape == "Rectangular")
			{
				_RorCS[indStruc]=1;
				
				// get structure bounding box
				point startX(ssd.lookup("startX"));
				point endX(ssd.lookup("endX"));
				
				startX = OFtoOCW_ & (startX + translateOFMesh_);
				endX = OFtoOCW_ & (endX + translateOFMesh_);
				
				_BBoxS[indStruc*4] = Foam::min(startX[0], endX[0]);
				_BBoxS[indStruc*4 + 1] = Foam::max(startX[0], endX[0]);
				_BBoxS[indStruc*4+2] = Foam::min(startX[1], endX[1]);
				_BBoxS[indStruc*4 + 3] = Foam::max(startX[1], endX[1]);
				
			}
			else if (structureShape == "Cylindrical")
			{
				_RorCS[indStruc]=2;
				
				point centre(ssd.lookup("centre"));
				double radius(readScalar(ssd.lookup("radius")));
				
				centre = OFtoOCW_ & (centre + translateOFMesh_);
				
				_BBoxS[indStruc*4] = centre[0];
				_BBoxS[indStruc*4 + 1] = centre[1];
				_BBoxS[indStruc*4+2] = radius;
				_BBoxS[indStruc*4 + 3] = 0;		
			}
			else
			{
				FatalErrorIn("oceanWave3D::setUpTwoWayCoupling()")
				<< "structureShape " << structureShape << nl 
				<<" is not implemented for coupling to OceanWave3D." 
				<< "structureShape must be Rectangular or Cylindrical"
				<< exit(FatalError) << endl << endl;
			}	
			
			// increase global structure index
			indStruc++;
		}
	}
		
	// declare pointers
	const int* RorC = new int[nDomains];
	double* BBoxD = new double[nDomains*4];
	const int* domainNr = new int[nRelax];
	double* BBoxR = new double[nRelax*4];
	const double* param = new double[nRelax];
	const int* dir = new int[nRelax];
	const int* ftype = new int[nRelax];
	const int* XorYorC = new int[nRelax];
	const int* domainNrS = new int[nStruc];
	const int* RorCS = new int[nStruc];
	double* BBoxS = new double[nStruc*4];
	
	//initialize Pointers
	RorC = _RorC;
	BBoxD = _BBoxD;
	domainNr = _domainNr;
	BBoxR = _BBoxR;
	param = _param;
	dir = _dir;
	ftype = _ftype;
	XorYorC = _XorYorC;
	domainNrS = _domainNrS;
	RorCS = _RorCS;
	BBoxS = _BBoxS;
	
	//JK: set up coupling in OceanWave3D and get gridpoints inside OpenFOAM Domain	
	preprocessofdomains_(&nDomains, RorC, BBoxD, &nRelax, domainNr, BBoxR, param, dir, ftype, XorYorC, &nStruc, domainNrS, RorCS, BBoxS);
	preprocessofpoints_();

	for(int i=0; i<__globalvariables_MOD_nofpoints; i++)
    {
		//JKTODO
		point p(__globalvariables_MOD_xofpoints[i], __globalvariables_MOD_yofpoints[i], 0.);	
		p = ( OCWtoOF_ & p ) - translateOFMesh_;
		OfPoints_.append(p);
	}
}

//JK: 
void oceanWave3D::setUpSampling()
{
    // Writing the sets file (master only)
	if (Pstream::master())
	{
		vector axes('x', 'y' ,'z');
		word vertAxis(axes[indVertCoord_]);
		
		scalar maxWaveHeight(0);
		maxWaveHeight = readScalar(coeffDict_.lookup("maxWaveHeight"));
		
		//get sideways coordinate direction index
		label indSideCoord(0);
		if (indVertCoord_ == 1)
		indSideCoord = 2;
		else if (indVertCoord_ == 2)
		indSideCoord = 1;
		else 
		{
				FatalErrorIn("void oceanWave3D::setUpSampling()")
			<< "vertival coordinate should be x or z"<< exit(FatalError);
		}
		  
		autoPtr<OFstream> gauges;

		gauges.reset(new OFstream("Coupling_sets"));

		gauges() << "sets" << nl << token::BEGIN_LIST << nl << incrIndent;

		for(int i=0; i<__globalvariables_MOD_nofpoints; i++)
		{
			gauges() << indent << "gauge_" << i << nl << indent
					 << token::BEGIN_BLOCK << incrIndent << nl;
			gauges() << indent << "type         face"
					 << token::END_STATEMENT << nl;
			gauges() << indent << "axis         " << vertAxis
					 << token::END_STATEMENT << nl;
			gauges() << indent << "start        " << token::BEGIN_LIST 
					 << OfPoints_[i][0]<< " "
					 << OfPoints_[i][indSideCoord] << " "
					 << seaLevel_-maxWaveHeight/2
					 << token::END_LIST << token::END_STATEMENT << nl;
			gauges() << indent << "end          " << token::BEGIN_LIST 
					 << OfPoints_[i][0]<< " "
					 << OfPoints_[i][indSideCoord] << " "
					 << seaLevel_+maxWaveHeight/2
					 << token::END_LIST << token::END_STATEMENT << nl;
			gauges() << indent << "nPoints      100" << token::END_STATEMENT << nl;
			gauges() << decrIndent << indent << token::END_BLOCK << nl << nl;
		}
		
		gauges() << decrIndent << token::END_LIST << token::END_STATEMENT << nl;
		
		gauges()().flush();
	}
	//JKTODO: does this work or will some processors read the file before it has been written
	
    fileName Edict("couplingSurfaceElevationDict");
    fileName Udict("couplingProbesDict");
    
    //instantiate sampledSurfaceElevation
    if (Pstream::parRun())
	{
		Edict = "../" + Edict;
		Udict = "../" + Udict;
	}
	sSets_ = new IOsampledSurfaceElevation
    (
        "couplingSurfaceElevation",
        mesh_,
        Edict,
        IOobject::MUST_READ,
        false
    );
    
    //instantiate velocity probes
	sProbes_ = new IOOCWprobes
	(
		"couplingProbes",
		mesh_,
		Udict,
		IOobject::MUST_READ,
		false
	);

}

//JK: 
void oceanWave3D::writeToOceanWave3D()
{

	//polyMesh::readUpdateState state = &mesh_.readUpdate(); //JKTODO this has to be fixed for moving meshes

	//sSets_.readUpdate(state); 

	scalarField EtaResult(0);
	sSets_->sampleIntegrateAndReturn(EtaResult);
	
	//only master has valid result
	if (Pstream::master())
	{
		if (EtaResult.size() != __globalvariables_MOD_nofpoints)
        {
			FatalErrorIn("void oceanWave3D::writeToOceanWave3D()")
            << "Number of obtained surface elevation samples does"<< nl
            << "not fit with number of evaluated Points" << exit(FatalError);
        }
		
		
		forAll (EtaResult, seti)
		{
			// write surface elevation to OceanWave3D variable respecting the change of coordinate system
			__globalvariables_MOD_eof[seti] = EtaResult[seti] - seaLevel_;
			// update OfPoints to current surface elevation
			OfPoints_[seti][indVertCoord_] = EtaResult[seti];
		}
	}
	
	Pstream::scatter(OfPoints_);
	
			//JKTODO: submerge Probes slightly
			List<point> probePoints(0);
			probePoints.setSize(OfPoints_.size());
			for(int i = 0; i < OfPoints_.size(); i++)
			{
				probePoints[i] = OfPoints_[i];
				probePoints[i][2] = probePoints[i][2] - 0.0754; //JKTODO!!!!!!
			}
	sProbes_ -> UpdateProbes(OfPoints_);
	
	
	vectorField UResult(0);
	sProbes_ -> sampleAndReturn(UResult);
	
	//only master has valid result
	if (Pstream::master())
	{
		if (UResult.size() != __globalvariables_MOD_nofpoints)
        {
			FatalErrorIn("void oceanWave3D::writeToOceanWave3D()")
            << "Number of obtained velocity samples does"<< nl
            << "not fit with number of evaluated Points" << exit(FatalError);
        }
		
		forAll (UResult, seti)
		{
			__globalvariables_MOD_uxof[seti] = (OFtoOCW_ & UResult[seti])[0];
			__globalvariables_MOD_uyof[seti] = (OFtoOCW_ & UResult[seti])[1];
			__globalvariables_MOD_uzof[seti] = (OFtoOCW_ & UResult[seti])[2];
		}
		
		
		//Write OF-Solution to OCW3D
		
		if(couplingType_=="eta")
			writeoftoocw3d_eta_();
		else if( couplingType_=="eta_w")
			writeoftoocw3d_eta_w_();
		else if( couplingType_=="eta_ux_uy")
			writeoftoocw3d_eta_ux_uy_();
		else if( couplingType_=="fully")
			writeoftoocw3d_fully_();
		else if( couplingType_=="oneWay")
		{}
		else
			FatalErrorIn("void oceanWave3D::writeToOceanWave3D()")
            << "unknown coupling type:"<< couplingType_ << nl
            << "must be eta, eta_w, eta_ux_uy, fully or oneWay" 
            << exit(FatalError);
	}
}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void oceanWave3D::step()
{

		scalar beforeTime = rT_.elapsedCpuTime();
		
	if (Pstream::master())
	{
		// Update intervals, if the old one is finished
		updateIntervals();

		// Perform time steps in OceanWave3D until OpenFoam has to be used
		timeStepOceanWave3D();
	}
	
	//JK: Read OF-Solution at OCW3D grid point locations 
	writeToOceanWave3D();
	
	if (Pstream::master())
	{	
		// Take a single time step in OceanWave3D and return to OpenFoam
		takeTimeStep(true);

		writeExternal();
	}
		Info << "External step: " << rT_.elapsedCpuTime() - beforeTime << " s."
			 << endl;
}


void oceanWave3D::close()
{
	if (Pstream::master())
	{
		// If used for setWaveField at t = 0, there is nothing to close
		if (0 < __globalvariables_MOD_time)
		{
			closevariables_();
		}
	}
}


scalar oceanWave3D::eta
(
    const point& x,
    const scalar& time
) const
{	
	point endP(point::zero);
	endP[0] = -1000000;
	endP[1] = -1000000;
	endP[2] = -1000000;
	List<point> endList(Pstream::nProcs());
	for (int proc = 0; proc < Pstream::nProcs(); proc++)
	{
		endList[proc] = endP;
	}
		
	//put all points to sample in a list, gather on master processor and scatter to all processors
	List<point> samplePoints(Pstream::nProcs());
	samplePoints = zero();
	samplePoints[Pstream::myProcNo()] = x;
	Pstream::gatherList(samplePoints);
	Pstream::scatterList(samplePoints);

	int tag = Pstream::allocateTag("Eta");
		
	if (Pstream::master())
	{
		while (samplePoints != endList)
		{	
			// Create list with results
			scalarList results(Pstream::nProcs());
			results = zero();
			
			//process points from all processors on master node
			for (int proc = 0; proc < Pstream::nProcs(); proc++)
			{
				if (samplePoints[proc] != endP)
				{

					//~ samplePoints[proc] = waveProps_->U(samplePoints[proc], mesh_.time().value());
					// do sampling:
						// Rotate the point x according to the predefined rotation matrix
						vector xx = OFtoOCW_ & (samplePoints[proc] + translateOFMesh_);

						// Create output
						double eta(0);
						
						// Create location in Fortran-format based on rotated coordinates
						double x0[3];
						x0[0] = xx[0];
						x0[1] = xx[1];
						x0[2] = xx[2] - seaLevel_;  // Notice displacement of coordinate system in OceanWave3D

						// Evaluate the surface elevation
						openfoaminterface_eta_(&x0,&eta);

						// Multiply by the ramping factor
						eta *= factor(time);
						eta += seaLevel_;
						
						//save result in list
						results[proc] = eta;
						
					if (proc != Pstream::masterNo())
					{
						// send result to slave
						OPstream toSlave(Pstream::blocking, proc, 0, 10);
						toSlave << eta;
					}
				}	
			}
					
			if (samplePoints[Pstream::masterNo()] != endP)
			{
				// there are still points to be sampled on the master!
				// Return the solution and come back with next point
				Pstream::freeTag("Eta", tag);
				return results[Pstream::masterNo()];
			}
			
			//gather lists from all processors
			Pstream::gatherList(samplePoints);
			Pstream::scatterList(samplePoints);
		}	
	}
	else
	{
		if (x != endP)
		{
			// recieve result from master and return
			IPstream fromMaster(Pstream::blocking, Pstream::masterNo(), 0, 10);
			double eta(0);
			fromMaster >> eta;
		
			// Return the solution
			Pstream::freeTag("Eta", tag);
			return eta;
		}
		else
		{
			//wait for all requests from other processors to finish
			while (samplePoints != endList)
			{
				Pstream::gatherList(samplePoints);
				Pstream::scatterList(samplePoints);
			}
		}
	}

	// Return endpoint
	Pstream::freeTag("Eta", tag);
	return -1000000;
}


//scalar oceanWave3D::ddxPd
//(
//    const point& x,
//    const scalar& time,
//    const vector& unitVector
//) const
//{
//    return 0.0;
//}


scalar oceanWave3D::pExcess
(
    const point& x,
    const scalar& time
) const
{
    return 0.0;
}


vector oceanWave3D::U
(
    const point& x,
    const scalar& time
) const
{
	point endP(point::zero);
	endP[0] = -1000000;
	endP[1] = -1000000;
	endP[2] = -1000000;
	List<point> endList(Pstream::nProcs());
	for (int proc = 0; proc < Pstream::nProcs(); proc++)
	{
		endList[proc] = endP;
	}
		
	//put all points to sample in a list, gather on master processor and scatter to all processors
	List<point> samplePoints(Pstream::nProcs());
	samplePoints = zero();
	samplePoints[Pstream::myProcNo()] = x;
	Pstream::gatherList(samplePoints);
	Pstream::scatterList(samplePoints);

	int tag = Pstream::allocateTag("OCW3DU");
		
	if (Pstream::master())
	{
		while (samplePoints != endList)
		{	
			//process points from all processors on master node
			for (int proc = 0; proc < Pstream::nProcs(); proc++)
			{
				if (samplePoints[proc] != endP)
				{

					//~ samplePoints[proc] = waveProps_->U(samplePoints[proc], mesh_.time().value());
					// do sampling:
						// Rotate the point x according to the predefined rotation matrix
						vector xx = OFtoOCW_ & (samplePoints[proc] + translateOFMesh_);

						// Map the coordinates to fortran format
						double x0[3];

						x0[0] = xx[0];
						x0[1] = xx[1];
						x0[2] = xx[2] - seaLevel_;

						// Make the return variables
						double utemp(0);
						double vtemp(0);
						double wtemp(0);

						// Evaluate the velocity in the given point
						openfoaminterface_u_(&x0,&utemp,&vtemp,&wtemp);

						// Map the solution of OF-format but still in rotated form
						//~ 
						samplePoints[proc].x() = utemp;
						samplePoints[proc].y() = vtemp;
						samplePoints[proc].z() = wtemp;

						// Rotate the solution back to the defined coordinate system in OpenFoam
						samplePoints[proc] = OCWtoOF_ & samplePoints[proc];

						// Multiply by the ramping factor
						samplePoints[proc] *= factor(time);
					
					if (proc != Pstream::masterNo())
					{
						// send result to slave
						OPstream toSlave(Pstream::blocking, proc, 0, tag);
						toSlave << samplePoints[proc];
					}
				}	
			}
					
			if (samplePoints[Pstream::masterNo()] != endP)
			{
				// there are still points to be sampled on the master
				// Return the solution and come back with next point
				Pstream::freeTag("OCW3DU", tag);
				return samplePoints[Pstream::masterNo()];
			}
			
			//gather lists from all processors
			Pstream::gatherList(samplePoints);
			Pstream::scatterList(samplePoints);
		}	
	}
	else
	{
		if (x != endP)
		{
			// recieve result from master and return
			IPstream fromMaster(Pstream::blocking, Pstream::masterNo(), 0, tag);
			vector U(vector::zero);
			fromMaster >> U;
			
			// Return the solution
			Pstream::freeTag("OCW3DU", tag);
			return U;
		}
		else
		{
			//wait for all requests from other processors to finish
			while (samplePoints != endList)
			{
				Pstream::gatherList(samplePoints);
				Pstream::scatterList(samplePoints);
			}
		}
	}

	// Return endpoint
	Pstream::freeTag("OCW3DU", tag);
	return endP;	
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace waveTheories
} // End namespace Foam

// ************************************************************************* //
