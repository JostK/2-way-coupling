SUBROUTINE WriteOFtoOCW3D_Fully
!
! Writes the free surface elevation and velocities calculated by OpenFOAM to the OCW3D solution
!
! By Jost Kemper
USE GlobalVariables, ONLY: WaveField, OfPoints, EOF, UxOF, UyOF, UzOF, alpha, beta, gamma, FineGrid,& 
						   GhostGridX, GhostGridY,GhostGridZ, dt, fileop, g, time, Phist,Ehist, k1_Phist, &
						    curvilinearONOFF
USE Precision
USE Constants

IMPLICIT NONE
  
INTEGER :: i, p
REAL(KIND=long) :: EOFtemp, EOCWtemp, UxOFtemp, UxOCWtemp, UyOFtemp, UyOCWtemp, UzOFtemp, UzOCWtemp, POFtemp, POCWtemp
REAL(KIND=long), DIMENSION(FineGrid%Nx+2*GhostGridX,FineGrid%Ny+2*GhostGridY) :: rhsE,rhsP, Ptemp

Write(*,*) 'Writing OpenFOAM solution to OceanWave3D (fully coupled)'


DO i=1, SIZE(OfPoints)
	! write surface elevation to wavefield
	EOCWtemp = WaveField%E(OfPoints(i)%xInd, OfPoints(i)%yInd)*(one - OfPoints(i)%relax)
	EOFtemp = EOF(i)*OfPoints(i)%relax
	WaveField%E(OfPoints(i)%xInd, OfPoints(i)%yInd) = EOFtemp + EOCWtemp
	
	! write Ux to Px
	IF (FineGrid%Nx>1) THEN
		UxOCWtemp = WaveField%Px(OfPoints(i)%xInd, OfPoints(i)%yInd)*(one - OfPoints(i)%relax)
		UxOFtemp = UxOF(i)*OfPoints(i)%relax
		WaveField%Px(OfPoints(i)%xInd, OfPoints(i)%yInd) = UxOFtemp + UxOCWtemp
	END IF
	
	! write Uy to Py
	IF (FineGrid%Ny>1) THEN
	UyOCWtemp = WaveField%Py(OfPoints(i)%xInd, OfPoints(i)%yInd)*(one - OfPoints(i)%relax)
	UyOFtemp = UyOF(i)*OfPoints(i)%relax
	WaveField%Py(OfPoints(i)%xInd, OfPoints(i)%yInd) = UyOFtemp + UyOCWtemp
	END IF
	
	! write Uz to W
	UzOCWtemp = WaveField%W(OfPoints(i)%xInd, OfPoints(i)%yInd)*(one - OfPoints(i)%relax)
	UzOFtemp = UzOF(i)*OfPoints(i)%relax
	WaveField%W(OfPoints(i)%xInd, OfPoints(i)%yInd) = UzOFtemp + UzOCWtemp
	
END DO

!smooth Eta, Px and Py
CALL OFsmoothing(wavefield%E, FineGrid%Nx+2*GhostGridX, FineGrid%Ny+2*GhostGridY)
IF (FineGrid%Nx>1) THEN
	CALL OFsmoothing(wavefield%Px, FineGrid%Nx+2*GhostGridX, FineGrid%Ny+2*GhostGridY)
END IF
IF (FineGrid%Ny>1) THEN
	CALL OFsmoothing(wavefield%Py, FineGrid%Nx+2*GhostGridX, FineGrid%Ny+2*GhostGridY)
END IF
CALL OFsmoothing(wavefield%W, FineGrid%Nx+2*GhostGridX, FineGrid%Ny+2*GhostGridY)

!Update derivates of Eta and smooth in between
IF (curvilinearONOFF==0) THEN
    ! Differentiation in the Free Surface plane
	IF (FineGrid%Nx>1) THEN
	   CALL UpdateGhostLayerX(Wavefield%E,Wavefield%SourceEx,FineGrid%Nx+2*GhostGridX,FineGrid%Ny+2*GhostGridY,&
       		FineGrid%DiffStencils,alpha,GhostGridX,GhostGridY)
       CALL DiffXEven(Wavefield%E,Wavefield%Ex, 1,FineGrid%Nx+2*GhostGridX,FineGrid%Ny+2*GhostGridY,1,FineGrid%DiffStencils,alpha)
       !smooth Ex
       CALL OFsmoothing(wavefield%Ex, FineGrid%Nx+2*GhostGridX, FineGrid%Ny+2*GhostGridY)
       CALL DiffXEven(Wavefield%E,Wavefield%Exx,2,FineGrid%Nx+2*GhostGridX,FineGrid%Ny+2*GhostGridY,1,FineGrid%DiffStencils,alpha)
	   !smooth Exx
       CALL OFsmoothing(wavefield%Exx, FineGrid%Nx+2*GhostGridX, FineGrid%Ny+2*GhostGridY)
	END IF

	IF (FineGrid%Ny>1) THEN
	   CALL UpdateGhostLayerY(Wavefield%E,Wavefield%SourceEy,FineGrid%Nx+2*GhostGridX,FineGrid%Ny+2*GhostGridY,&
       		FineGrid%DiffStencils,beta,GhostGridX,GhostGridY)
       CALL DiffYEven(Wavefield%E,Wavefield%Ey, 1,FineGrid%Nx+2*GhostGridX,FineGrid%Ny+2*GhostGridY,1,FineGrid%DiffStencils,beta)
       !smooth Ey
       CALL OFsmoothing(wavefield%Ey, FineGrid%Nx+2*GhostGridX, FineGrid%Ny+2*GhostGridY)
       CALL DiffYEven(Wavefield%E,Wavefield%Eyy,2,FineGrid%Nx+2*GhostGridX,FineGrid%Ny+2*GhostGridY,1,FineGrid%DiffStencils,beta)
	   !smooth Eyy
       CALL OFsmoothing(wavefield%Eyy, FineGrid%Nx+2*GhostGridX, FineGrid%Ny+2*GhostGridY)
	END IF
ELSE
	Write(*,*) 'Error in WriteOFtoOCW3D: curvilinear not implemented'
END IF


! Get new Phi by timeintegration with newly obtained OF results
CALL rhsFreeSurface3D(time,Wavefield,g,rhsE,rhsP,FineGrid%Nx+2*GhostGridX,FineGrid%Ny+2*GhostGridY)
Ptemp = Phist + half * dt * (rhsP + k1_Phist) 

! write Ptemp to P (only inside the OpenFOAM domain)
DO i=1, SIZE(OfPoints)
	POCWtemp = WaveField%P(OfPoints(i)%xInd, OfPoints(i)%yInd)*(one - OfPoints(i)%relax)
	POFtemp = Ptemp(OfPoints(i)%xInd, OfPoints(i)%yInd)*OfPoints(i)%relax
	WaveField%P(OfPoints(i)%xInd, OfPoints(i)%yInd) = POFtemp + POCWtemp
END DO

! smooth Phi
CALL OFsmoothing(wavefield%P, FineGrid%Nx+2*GhostGridX, FineGrid%Ny+2*GhostGridY)

!Update EtatHist and WHist
WaveField%WHist(:,:,1) = WaveField%W(:,:)
WaveField%EtatHist(:,:,1) = (WaveField%E(:,:) - Ehist(:,:))/dt





!write new velocities/Phi for debugging (2D)
IF (.TRUE.)	THEN

Open(fileop(15),file='UnewSmooth.chk',status='unknown')

DO p=1, SIZE(FineGrid%x) 

			!write(fileop(15),*)  FineGrid%x(p,1), Wavefield%Px(p,1), Wavefield%W(p,1)
			write(fileop(15),*)  FineGrid%x(p,1), Wavefield%E(p,1), Wavefield%Ex(p,1), Wavefield%Exx(p,1)
			!WRITE(*,*) EOF(p)
END DO

Close(fileop(15))

!STOP!!!

ENDIF

END SUBROUTINE WriteOFtoOCW3D_Fully
