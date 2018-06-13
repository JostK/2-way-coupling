SUBROUTINE PreprocessOfDomains(nDomains, RorC, BBoxD, nRelax, domainNr, BBoxR, param, dir, ftype, XorYorC)
!
! Sets up OfDomains structure 
!
! By Jost Kemper
USE GlobalVariables
IMPLICIT NONE

! Input variables
INTEGER 								:: nDomains			!nuber of enclose OpenFOAM Domains
INTEGER, DIMENSION(nDomains) 			:: RorC 			!Specifier wheter the OF domain is rectangular or Cylindrical, for each domain
REAL(KIND=long), DIMENSION(4*nDomains)  :: BBoxD			!Bounding Box, if rectangular: [xmin xmax ymin ymax]  if cylindrical [xCenter yCenter Radius 0], for each domain, Note: FORTRAN array INTEGER, DIMENSION(2,3,4) is equivalent to Cpp int i[4][3][2]
INTEGER									:: nRelax			!number of relaxation zones
INTEGER, DIMENSION(nRelax) 		  		:: domainNr			!Array with number of domain the relaxation zone belongs to
REAL(KIND=long), DIMENSION(4*nRelax) 	:: BBoxR			!Bounding Box, if rectangular: [xmin xmax ymin ymax]  if cylindrical [xCenter yCenter innerRadius outerRadius],for each Relaxation zone, Note: FORTRAN array INTEGER, DIMENSION(2,3,4) is equivalent to Cpp int i[4][3][2]
REAL(KIND=long), DIMENSION(nRelax)   	:: param      		!Parameter,for each Relaxation zone
INTEGER, DIMENSION(nRelax) 		  		:: dir        		!Direction of relaxation function -1 or 1,for each Relaxation zone
INTEGER, DIMENSION(nRelax)              :: ftype          	!relaxation function to be used,for each Relaxation zone
INTEGER, DIMENSION(nRelax)              :: XorYorC       	!coordinate direction for relaxation funtion,for each Relaxation zone
!Lokal variables
INTEGER :: i, j, k, relaxCount

ALLOCATE(OfDomains(nDomains))

Do i=1, nDomains
	SELECT CASE (RorC(i))
		CASE (1)
			OfDomains(i)%RorC = 'R'
		CASE (2)
			OfDomains(i)%RorC = 'C'
		CASE DEFAULT
			PRINT*, 'Error: RorC must be 1 or 2'
			STOP
	END SELECT
	
	OfDomains(i)%BBox = BBoxD(1+(i-1)*4 : 4+(i-1)*4) !Note: FORTRAN array INTEGER, DIMENSION(2,3,4) is equivalent to Cpp int i[4][3][2]
	
	relaxCount=0
	k=0
	
	DO j=1, nRelax
		IF (domainNr(j) == i) THEN
			relaxCount = relaxCount + 1		
		END IF
	END DO
	
	ALLOCATE(OfDomains(i)%RelaxZones(relaxCount))
	
	DO j=1, nRelax
		IF (domainNr(j) == i) THEN
			k = k + 1
			
			OfDomains(i)%RelaxZones(k)%BBox = BBoxR(1+(j-1)*4 : 4+(j-1)*4)!Note: FORTRAN array INTEGER, DIMENSION(2,3,4) is equivalent to Cpp int i[4][3][2]
			OfDomains(i)%RelaxZones(k)%param = param(j)
			OfDomains(i)%RelaxZones(k)%dir = dir(j)
			OfDomains(i)%RelaxZones(k)%ftype = ftype(j)
			
			SELECT CASE (XorYorC(j))
				CASE (1)
					OfDomains(i)%RelaxZones(k)%XorY = 'X'
				CASE (2)
					OfDomains(i)%RelaxZones(k)%XorY = 'Y'
				CASE (3)
					OfDomains(i)%RelaxZones(k)%XorY = 'C'
				CASE DEFAULT
					PRINT*, 'Error: XorYorC must be 1 or 2 or 3'
					STOP
			END SELECT
			
		END IF
	END DO
	
END DO

!DEBUG
WRITE(*,*)OfDomains(1)%RelaxZones(1)%dir
WRITE(*,*)OfDomains(1)%RelaxZones(2)%dir
END SUBROUTINE PreprocessOfDomains
