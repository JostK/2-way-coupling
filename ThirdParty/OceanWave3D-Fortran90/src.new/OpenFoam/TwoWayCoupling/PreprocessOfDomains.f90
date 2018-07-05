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
INTEGER :: i, j, k, relaxCount, p, q

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
IF (.TRUE.)	THEN

Open(fileop(14),file='OfDomain.chk',status='unknown')

!~ 		write(fileop(14),*) nDomains
!~ 		write(fileop(14),*) RorC
!~ 		write(fileop(14),*) BBoxD
!~ 		write(fileop(14),*) nRelax
!~ 		write(fileop(14),*)	DomainNr
!~ 		write(fileop(14),*)	BBoxR
!~ 		write(fileop(14),*)	param
!~ 		write(fileop(14),*)	dir
!~ 		write(fileop(14),*)	ftype
!~ 		write(fileop(14),*)	XorYorC

DO p=1, size( OfDomains)

	write(fileop(14),*) "******Domain  ", p, "******"
	write(fileop(14),*) "RorC:  ", OfDomains(p)%RorC 
	write(fileop(14),*) "BBox:  ", OfDomains(p)%BBox
	DO q=1, size( OfDomains(p)%RelaxZones )
	
		write(fileop(14),*) " "
		write(fileop(14),*) "**relaxation zone  ", q, "**"
		write(fileop(14),*) "BBox:  ", OfDomains(p)%RelaxZones(q)%BBox
		write(fileop(14),*) "param:  ", OfDomains(p)%RelaxZones(q)%param
		write(fileop(14),*) "dir:  ", OfDomains(p)%RelaxZones(q)%dir
		write(fileop(14),*) "ftype:  ", OfDomains(p)%RelaxZones(q)%ftype
		write(fileop(14),*) "XorY:  ", OfDomains(p)%RelaxZones(q)%XorY
		
	END DO
	write(fileop(14),*) " "
	
END DO
Close(fileop(14))

ENDIF

END SUBROUTINE PreprocessOfDomains
