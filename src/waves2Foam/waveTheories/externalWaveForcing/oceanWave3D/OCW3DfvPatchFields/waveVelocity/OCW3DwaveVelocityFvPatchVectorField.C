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

#include "OCW3DwaveVelocityFvPatchVectorField.H"
#include "addToRunTimeSelectionTable.H"

#if EXTBRANCH==1
    #if 310<OFVERSION
        #include "foamTime.H"
    #else
        #include "Time.H"
    #endif
#elif OFPLUSBRANCH==1
    #include "Time.H"
#else
    #include "Time.H"
#endif

#include "dimensionedVector.H"
#include "volMesh.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

OCW3DwaveVelocityFvPatchVectorField::OCW3DwaveVelocityFvPatchVectorField
(
    const fvPatch& p,
    const DimensionedField<vector, volMesh>& iF
)
:
    mixedFvPatchField<vector>(p, iF),
#if EXTBRANCH==1
    convexPolyhedral(this->dimensionedInternalField().mesh(), true),
#elif OFPLUSBRANCH==1
    #if OFVERSION<1706
        convexPolyhedral(this->dimensionedInternalField().mesh(), true),
    #else
        convexPolyhedral(this->internalField().mesh(), true),
    #endif
#else
    #if OFVERSION<400
        convexPolyhedral(this->dimensionedInternalField().mesh(), true),
    #else
        convexPolyhedral(this->internalField().mesh(), true),
    #endif
#endif
    waveProps_
    (
        waveTheories::waveTheory::New
        (
            this->patch().name(),
#if EXTBRANCH==1
            this->dimensionedInternalField().mesh()
#elif OFPLUSBRANCH==1
    #if OFVERSION<1706
            this->dimensionedInternalField().mesh()
    #else
            this->internalField().mesh()
    #endif
#else
    #if OFVERSION<400
            this->dimensionedInternalField().mesh()
    #else
            this->internalField().mesh()
    #endif
#endif
        )
    )
{
    this->refValue() = pTraits<vector>::zero;
    this->refGrad() = pTraits<vector>::zero;
    this->valueFraction() = 0.0;

}


OCW3DwaveVelocityFvPatchVectorField::OCW3DwaveVelocityFvPatchVectorField
(
    const OCW3DwaveVelocityFvPatchVectorField& ptf,
    const fvPatch& p,
    const DimensionedField<vector, volMesh>& iF,
    const fvPatchFieldMapper& mapper
)
:
    mixedFvPatchField<vector>(ptf, p, iF, mapper),
#if EXTBRANCH==1
    convexPolyhedral(this->dimensionedInternalField().mesh(), true),
#elif OFPLUSBRANCH==1
    #if OFVERSION<1706
        convexPolyhedral(this->dimensionedInternalField().mesh(), true),
    #else
        convexPolyhedral(this->internalField().mesh(), true),
    #endif
#else
    #if OFVERSION<400
        convexPolyhedral(this->dimensionedInternalField().mesh(), true),
    #else
        convexPolyhedral(this->internalField().mesh(), true),
    #endif
#endif
    waveProps_(ptf.waveProps_)
{
}


OCW3DwaveVelocityFvPatchVectorField::OCW3DwaveVelocityFvPatchVectorField
(
    const fvPatch& p,
    const DimensionedField<vector, volMesh>& iF,
    const dictionary& dict
)
:
    mixedFvPatchField<vector>(p, iF),
#if EXTBRANCH==1
    convexPolyhedral(this->dimensionedInternalField().mesh(), true),
#elif OFPLUSBRANCH==1
    #if OFVERSION<1706
        convexPolyhedral(this->dimensionedInternalField().mesh(), true),
    #else
        convexPolyhedral(this->internalField().mesh(), true),
    #endif
#else
    #if OFVERSION<400
        convexPolyhedral(this->dimensionedInternalField().mesh(), true),
    #else
        convexPolyhedral(this->internalField().mesh(), true),
    #endif
#endif
    waveProps_
    (
        waveTheories::waveTheory::New
        (
            this->patch().name(),
#if EXTBRANCH==1
            this->dimensionedInternalField().mesh()
#elif OFPLUSBRANCH==1
    #if OFVERSION<1706
            this->dimensionedInternalField().mesh()
    #else
            this->internalField().mesh()
    #endif
#else
    #if OFVERSION<400
            this->dimensionedInternalField().mesh()
    #else
            this->internalField().mesh()
    #endif
#endif
        )
    )
{
    evaluate();
}


OCW3DwaveVelocityFvPatchVectorField::OCW3DwaveVelocityFvPatchVectorField
(
    const OCW3DwaveVelocityFvPatchVectorField& ptf,
    const DimensionedField<vector, volMesh>& iF
)
:
    mixedFvPatchField<vector>(ptf, iF),
#if EXTBRANCH==1
    convexPolyhedral(this->dimensionedInternalField().mesh(), true),
#elif OFPLUSBRANCH==1
    #if OFVERSION<1706
        convexPolyhedral(this->dimensionedInternalField().mesh(), true),
    #else
        convexPolyhedral(this->internalField().mesh(), true),
    #endif
#else
    #if OFVERSION<400
        convexPolyhedral(this->dimensionedInternalField().mesh(), true),
    #else
        convexPolyhedral(this->internalField().mesh(), true),
    #endif
#endif
    waveProps_
    (
        waveTheories::waveTheory::New
        (
            this->patch().name(),
#if EXTBRANCH==1
            this->dimensionedInternalField().mesh()
#elif OFPLUSBRANCH==1
    #if OFVERSION<1706
            this->dimensionedInternalField().mesh()
    #else
            this->internalField().mesh()
    #endif
#else
    #if OFVERSION<400
            this->dimensionedInternalField().mesh()
    #else
            this->internalField().mesh()
    #endif
#endif
        )
    )
{
}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void OCW3DwaveVelocityFvPatchVectorField::signedPointToSurfaceDistance
(
    const pointField& pp,
    scalarField& sd
)
{
	
    forAll (pp, pointi)
    {
        sd[pointi] = signedPointToSurfaceDistance(pp[pointi]);
    }
}


scalar OCW3DwaveVelocityFvPatchVectorField::signedPointToSurfaceDistance
(
    const point& pp
) const
{
	
    scalar temp = waveProps_->eta(pp, db().time().value() );
    temp += ( waveProps_->returnDir() & pp );
    temp *= -1.0;

    return temp;
}


// Update the coefficients associated with the patch field
void OCW3DwaveVelocityFvPatchVectorField::updateCoeffs()
{
	
    if (this->updated())
    {
        return;
    }
    

#if EXTBRANCH==1
    const fvMesh& mesh = this->dimensionedInternalField().mesh();
#elif OFPLUSBRANCH==1
    #if OFVERSION<1706
        const fvMesh& mesh = this->dimensionedInternalField().mesh();
    #else
        const fvMesh& mesh = this->internalField().mesh();
    #endif
#else
    #if OFVERSION<400
        const fvMesh& mesh = this->dimensionedInternalField().mesh();
    #else
        const fvMesh& mesh = this->internalField().mesh();
    #endif
#endif
    const word patchName = this->patch().name();
    const label patchID = mesh.boundaryMesh().findPatchID(patchName);
    const scalarField& magSf( mesh.magSf().boundaryField()[patchID] );

    const label start = patch().patch().start();
//JK:
point endP(point::zero);
endP[0] = -1000000;
endP[1] = -1000000;
endP[2] = -1000000;
List<localFace> lf(magSf.size());
forAll (magSf, facei)
{
	//~ localFace lf = this->divideFace(facei + start);
	lf[facei] = this->divideFace(facei + start);
}
//send end signal to eta from all processors since this might have been called 
//by some processors during divideFace
waveProps_->eta(endP, mesh_.time().value());
	
	forAll (magSf, facei)
    {
        if (lf[facei].isNegFace())
        {          
				this->refValue()[facei]
                = waveProps_->U( lf[facei].negCentre(), db().time().value() );
        }
        else
        {
            this->refValue()[facei]
                = waveProps_->windVelocity( db().time().value() );
        }

        this->refGrad()[facei]       = vector::zero;
        this->valueFraction()[facei] = 1.0;
    }	   
    
//JK: send end signal to U from all processors 
waveProps_->U(endP, mesh_.time().value());
}

// Evaluate the field on the patch
void OCW3DwaveVelocityFvPatchVectorField::evaluate()
{
    if (!this->updated())
    {
        this->updateCoeffs();
    }

    Field<vector>::operator=
    (
        this->valueFraction()*this->refValue()
      +
        (1.0 - this->valueFraction())*
        (
            this->patchInternalField()
          + this->refGrad()/this->patch().deltaCoeffs()
        )
    );

    fvPatchField<vector>::evaluate();
}


// Write
void OCW3DwaveVelocityFvPatchVectorField::write(Ostream& os) const
{
    fvPatchField<vector>::write(os);
    this->refValue().writeEntry("refValue", os);
    this->refGrad().writeEntry("refGradient", os);
    this->valueFraction().writeEntry("valueFraction", os);
    this->writeEntry("value", os);
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

makePatchTypeField(fvPatchVectorField, OCW3DwaveVelocityFvPatchVectorField);

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //
