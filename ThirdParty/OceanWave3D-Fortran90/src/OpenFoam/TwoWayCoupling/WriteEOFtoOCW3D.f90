SUBROUTINE WriteEOFtoOCW3D
!
! Writes the free surface elevation calculated by OpenFOAM to the OCW3D solution
!
! By Jost Kemper
USE GlobalVariables
IMPLICIT NONE
INTEGER :: i, p
REAL(KIND=long) :: EOFtemp, EOCWtemp

DO i=1, SIZE(OfPoints)

	EOCWtemp = WaveField%E(OfPoints(i)%xInd, OfPoints(i)%yInd)*(one - OfPoints(i)%relax)
	EOFtemp = EOF(i)*OfPoints(i)%relax
	WaveField%E(OfPoints(i)%xInd, OfPoints(i)%yInd) = EOFtemp + EOCWtemp
		
END DO



!wite for debugging
IF (.TRUE.)	THEN

Open(fileop(14),file='EOF.chk',status='unknown')

DO p=1, SIZE(EOF) 

			write(fileop(14),*)  EOF(p)
			!WRITE(*,*) EOF(p)
END DO

Close(fileop(13))

		!CALL WriteEOFtoOCW3D()
ENDIF

END SUBROUTINE WriteEOFtoOCW3D
