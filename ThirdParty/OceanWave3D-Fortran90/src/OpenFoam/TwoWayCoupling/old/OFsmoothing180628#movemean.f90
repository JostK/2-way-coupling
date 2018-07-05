SUBROUTINE OFsmoothing(field, fieldmask, nx ,ny , L_smooth )
!
!Basic smoothing function for Wavefield obtained from OpenFOAM
!
! By Jost Kemper
USE Constants
USE CONV1D
USE CONV2D
IMPLICIT NONE
INTEGER :: nx, ny, L_smooth, i, j
REAL(KIND=long) :: avrg, stdDev
REAL(KIND=long), DIMENSION(nx, ny) :: field, tempField 
INTEGER, DIMENSION(nx, ny) :: fieldmask, resmask
REAL(KIND=long), DIMENSION(L_smooth) :: kernel2D
INTEGER, DIMENSION(L_smooth) :: kernelflag2D
REAL(KIND=long), DIMENSION(L_smooth, L_smooth) :: kernel3D
INTEGER, DIMENSION(L_smooth, L_smooth) :: kernelflag3D
tempField = zero
kernel2D = one/L_smooth
kernelflag2D = 1
kernel3D = one/(L_smooth*L_smooth)
kernelflag3D = 1
resmask = 1

!Filter out values 8 times bigger than the standard deviation and set flag for corrupt value in fieldflag
!~ 	   avrg = SUM(field)/(nx*ny)
!~ 	   stdDev=(SUM((field-avrg)**two))**half
!~ DO i = 1, nx
!~ 	DO j = 1, ny
!~ 		IF (field(i,j) > 8. * stdDev) THEN
!~ 			field(i,j)=0
!~ 			fieldmask(i,j) =1
!~ 		END IF
!~ 	END DO
!~ END DO

IF (ny == 1) THEN
	!2D case
	CALL RUNMEAN1D(field, fieldmask, kernel2D, kernelflag2D, 0.8, tempField, resmask, nx, ny)
ELSE IF (nx == 1) THEN
	WRITE(*,*) 'Error in OFsmoothing: smoothing for nx = 1 has not ben implemented yet'
	STOP
ELSE
	!3D case
	CALL RUNMEAN2D(field, fieldmask, kernel3D, kernelflag3D, 0.8, tempField, resmask, nx, ny)
END IF

field = tempField

END SUBROUTINE OFsmoothing
