SUBROUTINE OFsmoothing(field ,nx ,ny , L_smooth )
!
!Basic smoothing function for Wavefield obtained from OpenFOAM
!
! By Jost Kemper
USE Constants
USE GlobalVariables, ONLY: nOfPoints
IMPLICIT NONE
INTEGER :: nx, ny, L_smooth, i_flag, N_smoothed, j, i
REAL(KIND=long), DIMENSION(nx, ny) :: field, tempField, alpha_s
REAL(KIND=long) :: avrg, stdDev, tol
!CHARACTER (len=2) :: fieldname


j=1
N_smoothed =0
tol = 0.8
L_smooth=5
alpha_s=zero
tempField = field
!Do j=1,ny
	DO i=L_smooth, nx-(L_smooth-1)
	
	   ! get average and standard deviation over a length of L_smooth
	   avrg = SUM(field(i-(L_smooth-1):i,j))/L_smooth
	   stdDev=(SUM((field(i-(L_smooth-1):i,j)-avrg)**two))**half
!~ 	   WRITE(*,*) field(i-(L_smooth-1):i,j)
!~ 	   WRITE(*,*) sum(field(i-(L_smooth-1):i,j))
!~ 	   WRITE(*,*) avrg
!~ 	   WRITE(*,*) stdDev
	   
	   ! if the deviation is larger than "tol" times the standarddeviation smoothing is applied
	   IF(ABS(ABS(field(i, j))-ABS(avrg)) >= tol * stdDev)THEN
		  i_flag=1
		  N_smoothed = N_smoothed + 1
		  alpha_s(i-(L_smooth-1):i+(L_smooth-1),j)=0.25_long
	   END IF
	END DO
!END DO

WRITE(*,*)'smoothing', i_flag

IF(i_flag==1) THEN
	!Do j=1,ny
	   DO i=2,nx - 1
		  !smooth 
		  field(i,j)=alpha_s(i,j)*tempField(i-1,j)+(one-two*alpha_s(i,j))*tempField(i,j) &
			   +alpha_s(i,j)*tempField(i+1,j)
	   END DO
	!END DO
END IF

! write how many Points have been smoothed
!~ IF (.FALSE.) THEN

!~ WRITE(*,*) 'For ', fieldname, '   ', N_smoothed/nOfPoints*100., '% of the OfPoints were smoothed'

!~ END IF

END SUBROUTINE OFsmoothing
