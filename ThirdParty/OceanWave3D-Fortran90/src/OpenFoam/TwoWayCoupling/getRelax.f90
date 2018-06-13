REAL(KIND=long) FUNCTION getRelax(i, j, RZone) RESULT(relax)
!
! Gets Relaxation value for one Point
!
USE GlobalVariables
IMPLICIT NONE
!Input variables
INTEGER :: i, j
TYPE (RelaxZone) :: RZone
!Lokal variables
REAL(KIND=long) :: x(3), gam(3)

IF (RZone%XorY == 'X') THEN
	x(1) = RZone%BBox(1)
	x(2) = FineGrid%x(i, j)
	x(3) = RZone%BBox(2)
	CALL GammaFunctions(x, 3, RZone%dir, RZone%ftype, gam, RZone%param)
	relax = gam(2)
	
ELSE IF (RZone%XorY == 'Y') THEN
	x(1) = RZone%BBox(3)
	x(2) = FineGrid%y(i, j)
	x(3) = RZone%BBox(4)
	CALL GammaFunctions(x, 3, RZone%dir, RZone%ftype, gam, RZone%param)
	relax = gam(2)
	
ELSE IF (RZone%XorY == 'C') THEN
	!Circular relaxation zone
	x(1) = RZone%BBox(3) 	!inner radius
	!radius of evaluated point ((xCenter-xPoint)^2+(yCenter-yPoint)^2)^0.5
	x(2) = ((FineGrid%x(i, j) - RZone%BBox(1))**2 + (FineGrid%y(i, j) - RZone%BBox(2))**2)**0.5
	x(3) = RZone%BBox(4)	!outer radius
	CALL GammaFunctions(x, 3, RZone%dir, RZone%ftype, gam, RZone%param)
	relax = gam(2)

ELSE
	WRITE (*,*) 'Error: Define coordinate direction for relaxation zone. Should be "X" or "Y" or "C".'
	STOP
END IF
END FUNCTION getRelax
