SUBROUTINE PreprocessOfPoints
!
! Prepares array with Index of all Points inside the OpenFOAM domain with corrisponding gamma value
!
! By Jost Kemper
USE GlobalVariables
IMPLICIT NONE
INTEGER :: i, j, k, l, m, n, p 
INTEGER	:: nOfDomains
!Introduce Function return Types
LOGICAL isInBox
REAL(KIND=long) getRelax

nOfDomains=SIZE (OfDomains)
m=0
n=0

!Traverse trough Grid and count Points inside OF-domains
DO i=1, nOfDomains
	DO j = 1, FineGrid%Nx+2*GhostGridX
		DO 	k = 1, FineGrid%Ny+2*GhostGridY	
			IF (isInBox(j, k, OfDomains(i)%BBox, OfDomains(i)%RorC)) THEN
			
				m = m + 1
			
			END IF
		END DO
	END DO
END DO


IF (m > 0) THEN
	ALLOCATE(OfPoints(m))
	
	!Allocate Arrays for OpenFOAM
	ALLOCATE(UxOF(m))
	ALLOCATE(UyOF(m))
	ALLOCATE(UzOF(m))
	ALLOCATE(EOF(m))
	ALLOCATE(xOfPoints(m))
	ALLOCATE(yOfPoints(m))
	nOfPoints = m
	
ELSE
		PRINT*, 'Error: No OCW3D points inside OF-domain found'
		STOP
END IF 


!Traverse trough Grid and check if Points are in one of the OF-Domains
DO i=1, nOfDomains
	DO j = 1, FineGrid%Nx+2*GhostGridX
		DO 	k = 1, FineGrid%Ny+2*GhostGridY	
			IF (isInBox(j, k, OfDomains(i)%BBox, OfDomains(i)%RorC)) THEN
			
				n = n + 1
				
				OfPoints(n)%domainNr = i
				OfPoints(n)%xInd = j
				OfPoints(n)%yInd = k
				OfPoints(n)%relax = one
				
				!write x and y position of the Points into an Array for OpenFOAM
				xOfPoints(n) = FineGrid%x(j,k)
				yOfPoints(n) = FineGrid%y(j,k)
				
				DO l=1, SIZE (OfDomains(i)%RelaxZones)
				!check if Points are in one of the OF-Domains relaxation zones	
					IF (isInBox(j, k, OfDomains(i)%RelaxZones(l)%BBox, OfDomains(i)%RelaxZones(l)%XorY)) THEN
						OfPoints(n)%relax = getRelax(j, k, OfDomains(i)%RelaxZones(l))
						IF (OfDomains(i)%RelaxZones(l)%dir == -1) THEN
							!Reverse if direction is -1
							OfPoints(n)%relax = one-OfPoints(n)%relax
						END IF
					END IF
					
				END DO
			END IF
		END DO
	END DO
END DO



!check if number of points found in both loops is the same
IF (m /= n) THEN
		PRINT*, 'Error in PreprocessOfDomains.f90: m is not equal to n'
		STOP
END IF



!wite for debugging
IF (.FALSE.)	THEN

Open(fileop(14),file='OfPoints.chk',status='unknown')

DO p=1, m 

			write(fileop(14),*)  OfPoints(p)%xInd, OfPoints(p)%yInd, OfPoints(p)%relax
			WRITE(*,*) OfPoints(p)%xInd, OfPoints(p)%yInd, OfPoints(p)%relax, FineGrid%x(OfPoints(p)%xInd,1)
END DO

Close(fileop(13))

		!CALL WriteEOFtoOCW3D()
ENDIF


END SUBROUTINE PreprocessOfPoints
