INTEGER FUNCTION isInBox(i, j, BBox, RorC) RESULT(isIn)
!
! Evaluates wheter a Gridponit with a certain index is inside or outside a bounding box or cylinder
!
USE GlobalVariables
USE Constants 
IMPLICIT NONE

!Input variables
INTEGER :: i, j
REAL(KIND=long) :: BBox(4)
CHARACTER :: RorC
!Lokal variables
REAL(KIND=long), DIMENSION(:,:), POINTER :: x, y
CHARACTER :: RorCtemp

!make lokal Pointers
x => FineGrid%x
y => FineGrid%y

!if used for relaxation zone RorC is X or Y in the rectangular case
RorCtemp = RorC
IF (RorCtemp == 'X' .OR. RorCtemp == 'Y') THEN
	RorCtemp = 'R'
ENDIF

	IF (RorCtemp == 'R') THEN
		!2D Cases
		IF (FineGrid%Nx ==1) THEN
			IF (      y(i,j) >= BBox(3) &
				.AND. y(i,j) <= BBox(4)) &
			THEN
				isIn = 1
			ELSE
				isIn = 0
			ENDIF
		ELSE IF (FineGrid%Ny ==1) THEN
			IF (	  x(i,j) >= BBox(1) &
				.AND. x(i,j) <= BBox(2)) &
			THEN
				isIn = 1
			ELSE
				isIn = 0
			ENDIF
		ELSE
		!3D case		
			IF (	  x(i,j) >= BBox(1) &
				.AND. x(i,j) <= BBox(2) &
				.AND. y(i,j) >= BBox(3) &
				.AND. y(i,j) <= BBox(4)) &
			THEN
				isIn = 1
			ELSE
				isIn = 0
			ENDIF
		ENDIF
		
	ELSE IF (RorCtemp == 'C') THEN
	!Calculate distance to center and ceck if <= radius
		IF ( ((BBox(1)-x(i,j))**two + (BBox(2)-y(i,j))**two)**half <= BBox(3) ) THEN
				isIn = 1
			ELSE
				isIn = 0
			ENDIF
		
	ELSE
	
		PRINT*, 'Error: isInBox only respects Rectangles (R) or Circles (C)'
		STOP
		
	ENDIF
	
END FUNCTION isInBox
