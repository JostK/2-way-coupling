SUBROUTINE WriteEOFtoOCW3D
!
! Writes the free surface elevation calculated by OpenFOAM to the OCW3D solution
!
! By Jost Kemper
USE GlobalVariables
IMPLICIT NONE
INTEGER :: i
REAL(KIND=long) :: EOFtemp, EOCWtemp

DO i=1, SIZE(OfPoints)

	EOCWtemp = WaveField%E(OfPoints(i)%xInd, OfPoints(i)%yInd)*(one - OfPoints(i)%relax)
	EOFtemp = EOF(i)*OfPoints(i)%relax
	WaveField%E(OfPoints(i)%xInd, OfPoints(i)%yInd) = EOFtemp + EOCWtemp
	
END DO

END SUBROUTINE WriteEOFtoOCW3D
