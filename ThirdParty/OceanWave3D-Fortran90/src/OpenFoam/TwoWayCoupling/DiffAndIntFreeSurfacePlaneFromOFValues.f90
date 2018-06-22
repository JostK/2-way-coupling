SUBROUTINE DiffAndIntFreeSurfacePlaneFromOFValues(Wavefield,GhostGridX,GhostGridY,FineGrid,alpha,beta)
! By Jost Kemper
USE Precision
USE Constants
USE DataTypes
USE GlobalVariables, ONLY: GhostGridZ, OfPoints, dx, dy, fileop
IMPLICIT NONE
INTEGER :: GhostGridX, GhostGridY, alpha, beta
TYPE (Level_def) :: FineGrid
TYPE(Wavefield_FS) :: Wavefield
!for Integration
INTEGER :: domainCount, xIndex, yIndex, i, lb, ub, j, p
REAL(KIND=long), DIMENSION(FineGrid%Nx+2*GhostGridX,FineGrid%Ny+2*GhostGridY) :: PtempX, PtempY, Ptemp
REAL(KIND=long) :: POFtemp, POCWtemp

! update derivates of surface elevation E
IF (FineGrid%Nx>1) THEN
   CALL UpdateGhostLayerX(Wavefield%E,Wavefield%SourceEx,FineGrid%Nx+2*GhostGridX,FineGrid%Ny+2*GhostGridY,&
		FineGrid%DiffStencils,alpha,GhostGridX,GhostGridY)
   CALL DiffXEven(Wavefield%E,Wavefield%Ex, 1,FineGrid%Nx+2*GhostGridX,FineGrid%Ny+2*GhostGridY,1,FineGrid%DiffStencils,alpha)
   CALL DiffXEven(Wavefield%E,Wavefield%Exx,2,FineGrid%Nx+2*GhostGridX,FineGrid%Ny+2*GhostGridY,1,FineGrid%DiffStencils,alpha)
END IF

IF (FineGrid%Ny>1) THEN
   CALL UpdateGhostLayerY(Wavefield%E,Wavefield%SourceEy,FineGrid%Nx+2*GhostGridX,FineGrid%Ny+2*GhostGridY,&
		FineGrid%DiffStencils,beta,GhostGridX,GhostGridY)
   CALL DiffYEven(Wavefield%E,Wavefield%Ey, 1,FineGrid%Nx+2*GhostGridX,FineGrid%Ny+2*GhostGridY,1,FineGrid%DiffStencils,beta)
   CALL DiffYEven(Wavefield%E,Wavefield%Eyy,2,FineGrid%Nx+2*GhostGridX,FineGrid%Ny+2*GhostGridY,1,FineGrid%DiffStencils,beta)
END IF

	


!write old Phi for debugging (2D case)
IF (.TRUE.)	THEN

Open(fileop(15),file='oldPhi.chk',status='unknown')

DO p=1, FineGrid%Nx+2*GhostGridX 

			write(fileop(15),*)  FineGrid%x(p,1), Wavefield%P(p,1)
			!WRITE(*,*) EOF(p)
END DO

Close(fileop(15))


ENDIF


! initialize temporary Potential fields
PtempX = zero
PtempY = zero
Ptemp = zero


DO domainCount = 1, MAXVAL(OfPoints%domainNr)

	yIndex = 0
	xIndex = 0


	!integrate ux in x direction
	IF (FineGrid%Nx>1) THEN
		! loop over y
		DO yIndex = MINVAL(OfPoints%yInd), MAXVAL(OfPoints%yInd)
			!initialize lower and upper bound to extreme values
			lb = HUGE(lb) 
			ub = 0
			
			!loop trough OfPoints and find min and max xInd for given yIndex in given Domain
			DO i = 1, SIZE(OfPoints)
				IF (OfPoints(i)%yInd == yIndex .AND. OfPoints(i)%domainNr == domainCount) THEN
					lb = min(lb, OfPoints(i)%xInd)
					ub = max(ub, OfPoints(i)%xInd)
				END IF
			END DO
			
			!only procede with this yIndex if points have ben found inside the current domain
			IF (lb /= HUGE(lb) .AND. ub /=0) THEN
			
				!integation shall start uotside the OpenFoam domain so lb and ub must be dereased ie. increased by one
				IF (lb > 1) THEN
					lb = lb - 1
				END IF
				IF (ub < FineGrid%Nx+2*GhostGridX) THEN
					ub = ub + 1
				END IF
				
				!Integrate using trapezoidal rule (no integration at lower Boundary so start at lb+1)
				DO xIndex = lb+1, ub
					PtempX(xIndex, yIndex) = PtempX(xIndex-1, yIndex) + dx*half*(wavefield%Px(xIndex-1,yindex) + wavefield%Px(xIndex,yindex))
				END DO
				
				!add integration constant (linear interpolated betwen value of P at lower and upper bound)
				!note at lb the value of Ptemp is now zero so it can be fittet with adding the old P at this point which is still
				!valid since lb is outside the OpenFOAM domain 
				!at ub the missmatch has to be evaluated first sice Ptemp is not zero here
				DO xIndex = lb, ub
					PtempX(xIndex, yIndex) = PtempX(xIndex, yIndex) + wavefield%P(lb, yIndex)* (one - REAL((xIndex-lb), KIND=long)/REAL((ub-lb),KIND=long)) &
											 + (wavefield%P(ub, yIndex)-PtempX(ub, yIndex))* REAL((xIndex-lb), KIND=long)/REAL((ub-lb), KIND=long)
				END DO			
			END IF	
		END DO
		
		!Write PtempX to Ptemp for 2D case
		Ptemp = PtempX
	END IF

	xIndex = 0
	yIndex = 0
	
	!integrate ux in y direction
	IF (FineGrid%Ny>1) THEN
		! loop over x
		DO xIndex = MINVAL(OfPoints%xInd), MAXVAL(OfPoints%xInd)
			!initialize lower and upper bound to extreme values
			lb = HUGE(lb) 
			ub = 0
			
			!loop trough OfPoints and find min and max yInd for given xIndex
			DO i = 1, SIZE(OfPoints)
				IF (OfPoints(i)%xInd == xIndex .AND. OfPoints(i)%domainNr == domainCount) THEN
					lb = min(lb, OfPoints(i)%yInd)
					ub = max(ub, OfPoints(i)%yInd)
				END IF
			END DO
			
			!only procede with this xIndex if points have ben found inside the current domain
			IF (lb /= HUGE(lb) .AND. ub /=0) THEN
				!integation shall start uotside the OpenFoam domain so lb and ub must be dereased ie. increased by one
				IF (lb > 1) THEN
					lb = lb - 1
				END IF
				IF (ub < FineGrid%Ny+2*GhostGridY) THEN
					ub = ub + 1
				END IF
				
				!Integrate using trapezoidal rule (no integration at lower Boundary so start at lb+1)
				DO yIndex = lb+1, ub
					PtempY(xIndex, yIndex) = PtempY(xIndex, yIndex-1) + dy*half*(wavefield%Py(xIndex,yIndex-1) + wavefield%Px(xIndex,yIndex))
				END DO	
				
					!add integration constant (linear interpolated betwen value of P at lower and upper bound)
					!note at lb the value of Ptemp is now zero so it can be fittet with adding the old P at this point which is still
					!valid since lb is outside the OpenFOAM domain 
					!at ub the missmatch has to be evaluated first sice Ptemp is not zero here
				DO yIndex = lb, ub
					PtempY(xIndex, yIndex) = PtempY(xIndex, yIndex) + wavefield%P(xIndex, lb) * (one- REAL((yIndex-lb), KIND=long)/REAL((ub-lb),KIND=long))&
										     + (wavefield%P(xIndex, ub) - PtempY(xIndex, ub)) * REAL((yIndex-lb), KIND=long)/REAL((ub-lb),KIND=long)

				END DO	
			END IF
		END DO
		
		!Write PtempY to Ptemp for 2D case
		Ptemp = PtempY
	END IF
END DO

IF (FineGrid%Ny>1 .AND. FineGrid%Nx>1) THEN
!take mean value from x and y integration if the case is 3D
Ptemp = half * (PtempX + PtempY)
END IF

!loop trough OfPoints and write Ptemp to Wavefield
!note that relaxation is aplied even though the integrated phi was already fitted to
!the the OceanWave3D Phi steadily by means of the integration constant but some unsteadyness
!might be introduced again by taking the mean from x and y integration.
DO j = 1, SIZE(OfPoints)
	POCWtemp = WaveField%P(OfPoints(j)%xInd, OfPoints(j)%yInd)*(one - OfPoints(j)%relax)
	POFtemp = Ptemp(OfPoints(j)%xInd, OfPoints(j)%yInd)*OfPoints(j)%relax
	WaveField%P(OfPoints(j)%xInd, OfPoints(j)%yInd) = POFtemp + POCWtemp
END DO





!write new Phi for debugging (2D case)
IF (.TRUE.)	THEN

Open(fileop(16),file='newPhi.chk',status='unknown')

DO p=1, FineGrid%Nx+2*GhostGridX 

			write(fileop(16),*)  FineGrid%x(p,1), Wavefield%P(p,1)
			!WRITE(*,*) EOF(p)
END DO

Close(fileop(16))

ENDIF



!write Ptemp for debugging (2D case)
IF (.TRUE.)	THEN

Open(fileop(15),file='Ptemp.chk',status='unknown')

DO p=1, FineGrid%Nx+2*GhostGridX 

			write(fileop(15),*)  FineGrid%x(p,1), Ptemp(p,1)
			!WRITE(*,*) EOF(p)
END DO

Close(fileop(15))

ENDIF


END SUBROUTINE 
