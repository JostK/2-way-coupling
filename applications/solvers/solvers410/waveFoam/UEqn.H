    MRF.correctBoundaryVelocity(U);
    
    
    //JK: 

				Damp = sand*rho*U*1/(1+exp(-100*(alpha2-scalar(0.8))));


    fvVectorMatrix UEqn
    (
        fvm::ddt(rho, U) + fvm::div(rhoPhi, U)
      + MRF.DDt(rho, U)
      + turbulence->divDevRhoReff(rho, U)
      // JK: edit
      + Damp
     ==
        fvOptions(rho, U)
    );

    UEqn.relax();

    fvOptions.constrain(UEqn);

    if (pimple.momentumPredictor())
    {
        solve
        (
            UEqn
         ==
            fvc::reconstruct
            (
                (
                    mixture.surfaceTensionForce()
                  - ghf*fvc::snGrad(rho)
                  - fvc::snGrad(p_rgh)
                ) * mesh.magSf()
            )
        );

        fvOptions.correct(U);
    }
        //JK:
        //~ U=U*1/(1+exp(-100*(alpha1-scalar(0.2))));
