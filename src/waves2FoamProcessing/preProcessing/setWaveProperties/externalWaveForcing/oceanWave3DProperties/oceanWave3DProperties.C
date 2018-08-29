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

#include "oceanWave3DProperties.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

defineTypeNameAndDebug(oceanWave3DProperties, 0);
addToRunTimeSelectionTable
(
    setWaveProperties,
    oceanWave3DProperties,
    setWaveProperties
);

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //


oceanWave3DProperties::oceanWave3DProperties
(
    const Time& rT,
    dictionary& dict,
    bool write
)
:
    setWaveProperties(rT, dict, write)
{
    Info << "\nConstructing: " << this->type() << endl;
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //


void oceanWave3DProperties::set( Ostream& os )
{
    // Write the beginning of the sub-dictionary
    writeBeginning( os );

    // Write the already given parameters
    writeGiven( os, "waveType" );

    os << endl;

    // Write the intervals
    writeGiven(os, "nIntervals");

    scalarField startTimes("startTimes", dict_, readLabel(dict_.lookup("nIntervals")));
    writeDerived(os, "startTimes", startTimes);

    scalarField endTimes("endTimes", dict_, readLabel(dict_.lookup("nIntervals")));
    writeDerived(os, "endTimes", endTimes);

    os << endl;

    // Write the ramp information
    writeGiven(os, "rampInterval");

    if (Switch(dict_.lookup("rampInterval")))
    {
    	writeGiven(os, "Tsoft");
    }

    os << endl;

    // Write the information for the mapping
    writeGiven(os, "mappingZone");

    // Set the translation of the OF-mesh
    writeGiven(os, "translateOpenFoamMesh");
    
    //
    //JK: Write information for two way coupling
    //
		
		os << endl;
		
		// Set coupling type
		writeGiven(os, "couplingType");
		
		wordList domainNames=dict_.lookup("domainNames");
		writeGiven(os, "domainNames");		
		
		writeGiven(os, "OCWrelaxationFuction");
		writeGiven(os, "OCWrelaxationParam");
		
		writeGiven(os, "maxWaveHeight");
		
		forAll (domainNames, domaini)
		{
			word dm(domainNames[domaini]);
			
			os << nl << indent << dm << "Coeffs" << nl;
			
			os << indent << token::BEGIN_BLOCK
			   << incrIndent << nl;

			dictionary sd( dict_.subDict(dm + "Coeffs") );
			
			ITstream domainShapeIT( sd.lookup("domainShape"));
			addITstream( os, "domainShape", domainShapeIT );
			word domainShape(sd.lookup("domainShape"));
			if (domainShape == "Rectangular")
			{
				ITstream startX( sd.lookup("startX"));
				addITstream( os, "startX", startX );
				
				ITstream endX( sd.lookup("endX"));
				addITstream( os, "endX", endX );
			}
			else if (domainShape == "Cylindrical")
			{
				ITstream centre( sd.lookup("centre"));
				addITstream( os, "centre", centre );
				
				ITstream radius( sd.lookup("radius"));
				addITstream( os, "radius", radius );
			}
			else
			{
				FatalErrorIn("oceanWave3DProperties::set()")
				<< "domainShape " << domainShape << " unknown." 
				<< "domainShape must be Rectangular or Cylindrical"
				<< exit(FatalError) << endl << endl;
			}	
			
			ITstream relaxationNames( sd.lookup("relaxationNames"));
			addITstream( os, "relaxationNames", relaxationNames );	
			
			ITstream structureNamesIT( sd.lookup("structureNames"));
			addITstream( os, "structureNames", structureNamesIT );			
			wordList structureNames=sd.lookup("structureNames");
			
			forAll (structureNames, structi)
			{
				word str(structureNames[structi]);
				
				os << nl << indent << str << "Coeffs" << nl;
				
				os << indent << token::BEGIN_BLOCK
				   << incrIndent << nl;

				dictionary ssd( sd.subDict(str + "Coeffs") );

				wordList tocS( ssd.toc() );

				forAll (tocS, item)
				{
					ITstream it( ssd.lookup(tocS[item]) );

					addITstream( os, tocS[item], it );
				}

				os << decrIndent << indent << token::END_BLOCK << endl;
			}
			os << decrIndent << indent << token::END_BLOCK << endl;
		}
	    
	   
    // Write the closing bracket
    writeEnding( os );
}



// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //
