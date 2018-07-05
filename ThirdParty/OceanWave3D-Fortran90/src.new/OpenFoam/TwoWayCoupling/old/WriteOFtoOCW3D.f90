SUBROUTINE WriteOFtoOCW3D
!
! Writes the free surface elevation and velocities calculated by OpenFOAM to the OCW3D solution
!
! By Jost Kemper
USE GlobalVariables, ONLY: WaveField, OfPoints, EOF, UxOF, UyOF, UzOF, alpha, beta, FineGrid,& 
						   GhostGridX, GhostGridY, dt, fileop, g, time, Phist, k1_Phist
USE Precision
USE Constants

IMPLICIT NONE
INTEGER :: i, p, smoothLenth
REAL(KIND=long) :: EOFtemp, EOCWtemp, UxOFtemp, UxOCWtemp, UyOFtemp, UyOCWtemp, UzOFtemp, UzOCWtemp, POFtemp, POCWtemp
REAL(KIND=long), DIMENSION(FineGrid%Nx+2*GhostGridX,FineGrid%Ny+2*GhostGridY) :: rhsE,rhsP, Ptemp
INTEGER, DIMENSION(FineGrid%Nx+2*GhostGridX,FineGrid%Ny+2*GhostGridY) :: emptyflag

DO i=1, SIZE(OfPoints)
	
	! write surface elevation
	EOCWtemp = WaveField%E(OfPoints(i)%xInd, OfPoints(i)%yInd)*(one - OfPoints(i)%relax)
	EOFtemp = EOF(i)*OfPoints(i)%relax
	WaveField%E(OfPoints(i)%xInd, OfPoints(i)%yInd) = EOFtemp + EOCWtemp
	
!~ 	! write Ux to Px
!~ 	IF (FineGrid%Nx>1) THEN
!~ 		UxOCWtemp = WaveField%Px(OfPoints(i)%xInd, OfPoints(i)%yInd)*(one - OfPoints(i)%relax)
!~ 		UxOFtemp = UxOF(i)*OfPoints(i)%relax
!~ 		WaveField%Px(OfPoints(i)%xInd, OfPoints(i)%yInd) = UxOFtemp + UxOCWtemp
!~ 	END IF
	
!~ 	! write Uy to Py
!~ 	IF (FineGrid%Ny>1) THEN
!~ 	UyOCWtemp = WaveField%Py(OfPoints(i)%xInd, OfPoints(i)%yInd)*(one - OfPoints(i)%relax)
!~ 	UyOFtemp = UyOF(i)*OfPoints(i)%relax
!~ 	WaveField%Py(OfPoints(i)%xInd, OfPoints(i)%yInd) = UyOFtemp + UyOCWtemp
!~ 	END IF
	
!~ 	! write Uz to W
!~ 	UzOCWtemp = WaveField%W(OfPoints(i)%xInd, OfPoints(i)%yInd)*(one - OfPoints(i)%relax)
!~ 	UzOFtemp = UzOF(i)*OfPoints(i)%relax
!~ 	WaveField%W(OfPoints(i)%xInd, OfPoints(i)%yInd) = UzOFtemp + UzOCWtemp
		
END DO

!write new velocities for debugging (2D)
IF (.FALSE.)	THEN

Open(fileop(14),file='UnewRaw.chk',status='unknown')

DO p=1, SIZE(FineGrid%x) 

			write(fileop(14),*)  FineGrid%x(p,1), Wavefield%Px(p,1), Wavefield%W(p,1)
			!WRITE(*,*) EOF(p)
END DO

Close(fileop(14))

!STOP!!!

ENDIF



!Update derivates of Eta (and inegrate new Phi for timestepping of FSBC)ISSWITCHEDOF
!~ CALL DiffAndIntFreeSurfacePlaneFromOFValues(Wavefield,GhostGridX,GhostGridY,FineGrid,alpha,beta)

!~ CALL rhsFreeSurface3D(time,Wavefield,g,rhsE,rhsP,FineGrid%Nx+2*GhostGridX,FineGrid%Ny+2*GhostGridY)
!~ Ptemp = Phist + half * dt * (rhsP + k1_Phist) 

!~ ! write Rtemp to P (only inside the OpenFOAM domain)
!~ DO i=1, SIZE(OfPoints)

!~ 	POCWtemp = WaveField%P(OfPoints(i)%xInd, OfPoints(i)%yInd)*(one - OfPoints(i)%relax)
!~ 	POFtemp = Ptemp(OfPoints(i)%xInd, OfPoints(i)%yInd)*OfPoints(i)%relax
!~ 	WaveField%P(OfPoints(i)%xInd, OfPoints(i)%yInd) = POFtemp + POCWtemp
!~ END DO



!~ !Update derivates again after integrating Phi
CALL DifferentiationsFreeSurfacePlane(Wavefield,GhostGridX,GhostGridY,FineGrid,alpha,beta)
!~ !-> increases stability (maybe update ghost layers is important)


!write old velocities/Phi for debugging (2D)
IF (.TRUE.)	THEN

Open(fileop(11),file='Uold.chk',status='unknown')

DO p=1, SIZE(FineGrid%x) 

			!write(fileop(11),*)  FineGrid%x(p,1), Wavefield%Px(p,1), Wavefield%W(p,1)
			!WRITE(*,*) EOF(p)
			write(fileop(11),*)  FineGrid%x(p,1), Wavefield%E(p,1), Wavefield%Ex(p,1), Wavefield%Exx(p,1)

END DO

Close(fileop(11))

ENDIF

!~ emptyflag = 0
!~ smoothLenth = 5
!~ CALL OFsmoothing(wavefield%Ex, emptyflag, FineGrid%Nx+2*GhostGridX, FineGrid%Ny+2*GhostGridY, smoothLenth)
!~ CALL OFsmoothing(wavefield%Exx, emptyflag, FineGrid%Nx+2*GhostGridX, FineGrid%Ny+2*GhostGridY, smoothLenth)

CALL OFsmoothing(wavefield%Exx, FineGrid%Nx+2*GhostGridX, FineGrid%Ny+2*GhostGridY)
!JK smooth Ex before gettin Exx

!~ !Update WHist
!~ WaveField%WHist(:,:,1) = WaveField%W(:,:)FineGrid%DiffStencils

!Update EtatHist -> leads to foating point exeptions
!WaveField%EtatHist(:,:,1) = (WaveField%E(:,:) - WaveField%EtatHist(:,:,2))/dt

!JKTODO: LocalSmoothing and detectBreaking could be done now if necessary
! -> does not help a lot since velocities are not somoothed




!write EOF for debugging
IF (.FALSE.)	THEN

Open(fileop(14),file='EOF.chk',status='unknown')

DO p=1, SIZE(EOF) 

			write(fileop(14),*)  EOF(p)
			!WRITE(*,*) EOF(p)
END DO

Close(fileop(14))

ENDIF


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

END SUBROUTINE WriteOFtoOCW3D
