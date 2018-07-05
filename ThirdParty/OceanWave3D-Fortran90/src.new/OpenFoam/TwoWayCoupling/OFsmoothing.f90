SUBROUTINE OFsmoothing(field, nx ,ny )
!
!Basic smoothing function for Wavefield obtained from OpenFOAM
!
! By Jost Kemper
USE Constants
USE GlobalVariables, ONLY: OfPoints

IMPLICIT NONE
integer :: nl, nr, m, nx, ny, i, j, k
PARAMETER( &
	nl=5,  &
	nr=5,  &
	m=4    )
integer :: index(nl+nr+1)
real(KIND=long) :: field(nx,ny), smoothField(nx,ny), c(nl+nr+1)
REAL(KIND=long) :: ValOCWtemp, ValOFtemp

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

!save copy of field for smoothing
smoothField=field        

! seek shift index for given case nl, nr, m (see savgol). 
index(1)=0 

! example: case nl=nr=5
! index(2)=-1; index(3)=-2; index(4)=-3; index(5)=-4; index(6)=-5
j=3
do i=2, nl+1
	index(i)=i-j
	j=j+2
end do	  

! index(7)= 5; index(8)= 4; index(9)= 3; index(10)=2; index(11)=1
j=2
do i=nl+2, nl+nr+1
	index(i)=i-j
	j=j+2
end do   

! calculate Savitzky-Golay filter coefficients
call savgol(c,nl+nr+1,nl,nr,0,m)

! Apply filter to input data
DO k=1, ny
  do i=1, nx-nr
    smoothField(i, k)=0.
    do j=1, nl+nr+1
	  if (i+index(j).gt.0) then  !skip left points that do not exist
	    smoothField(i, k)=smoothField(i, k)+c(j)*field(i+index(j), k)
      end if
    end do
  end do
END DO

!Apply only values inside the OpenFOAM domain
DO i=1, SIZE(OfPoints)
	! write surface elevation
	ValOCWtemp = field(OfPoints(i)%xInd, OfPoints(i)%yInd)*(one - OfPoints(i)%relax)
	ValOFtemp = smoothField(OfPoints(i)%xInd, OfPoints(i)%yInd)*OfPoints(i)%relax
	field(OfPoints(i)%xInd, OfPoints(i)%yInd) = ValOCWtemp + ValOFtemp
END DO

END SUBROUTINE OFsmoothing
