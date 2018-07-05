!********************************************************************
!* SMOOTHING AN ARRAY OF N ORDINATES Y's (ASCENDING ORDER ABCISSAS) *
!*           using Savitzky-Golay filter coefficients               * 
!* ---------------------------------------------------------------- *
!* Description:                                                     *
!* This program uses the routine SAVGOL for smoothing an array of   *
!* given ordinates (y's) that are in order of increasing abscissas  *
!* (x's), but without using the abscissas themselves supposed to be *
!* equally spaced. It first calculates the filter coefficients and  *
!* then applies the numerical filter to low-pass filter the data.   *
!* The user-specified parameter are: nl, nr and m  to enter "the    *
!* amount of smoothing", given roughly as the number of points over *
!* which the data should be smoothed.                               *
!* ---------------------------------------------------------------- *
!* Reference:  "Numerical Recipes By W.H. Press, B. P. Flannery,    *
!*              S.A. Teukolsky and W.T. Vetterling, Cambridge       *
!*              University Press, 1986 - 1992" [BIBLI 08].          *
!*                                                                  *
!*                              F90 Release By J-P Moreau, Paris.   *
!*                                     (www.jpmoreau.fr)            *
!********************************************************************
SUBROUTINE tsavgol(signal, nx, ny, nl, nr, m)
USE precision
IMPLICIT NONE

real(KIND=long)  signal(nx,ny), ysave(nx,ny), c(nl+nr+1)
integer nl, nr, m, index(nl+nr+1), nx, ny, i, j, k



!~   !open input and output file
!~   OPEN(UNIT=2,FILE='tsavgol.lst',STATUS='UNKNOWN')	                              
!~   OPEN(UNIT=1,FILE='smooth.dat',STATUS='OLD')
!~   !read number of input signal points in input file
!~   read(1,*)  ndata

!~   !read ndata couples T(i), Y(i) in input data file
!~   do i=1, ndata
!~     read(1,*)  temp, signal(i)
!~     if (i.eq.1)     tbegin=temp
!~     if (i.eq.ndata) tend=temp
!~   end do
!~   close(unit=1)

ysave=signal        !save unsmoothed signal


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

DO k=1, ny
!~   print *,' '
!~   print *,' Number of left points .......: ', nl
!~   print *,' Number of right points ......: ', nr
!~   print *,' Order of smoothing polynomial: ', m
!~   print *,' '
!~   print *,' Savitzky-Golay Filter Coefficients:'
!~   write(*,*) (c(i),i=1, nl+nr+1)

! Apply filter to input data
  do i=1, nx-nr
    signal(i, k)=0.
    do j=1, nl+nr+1
	  if (i+index(j).gt.0) then  !skip left points that do not exist
	    signal(i, k)=signal(i, k)+c(j)*ysave(i+index(j), k)
      end if
    end do
  end do

!~ ! write results to output file
!~   dt=(tend-tbegin)/(ndata-1)
!~   t=tbegin-dt
!~   write(2,*) '      Time          Y        Smoothed Y '
!~   write(2,*) '----------------------------------------'
!~   do i=1, ndata
!~     t=t+dt
!~     write(2,100)  t, ysave(i), signal(i)
!~   end do

!~   close(unit=2)
!~   print *,' '
!~   print *,'Results in file tsavgol.lst.'
!~   print *,' '
!~   stop

!~ 100 format('   ',F10.6,'   ',F10.6,'   ',F10.6)
END DO

END SUBROUTINE tsavgol


!~ SUBROUTINE savgol(c,np,nl,nr,ld,m)
!~ USE precision

!~ INTEGER ld,m,nl,np,nr,MMAX 
!~ real(KIND=long) c(np) 
!~ PARAMETER (MMAX=6)
!~ !-------------------------------------------------------------------------------------------- 
!~ !USES lubksb,ludcmp given below. 
!~ !Returns in c(1:np), in wrap-around order (see reference) consistent with the argument respns 
!~ !in routine convlv, a set of Savitzky-Golay filter coefficients. nl is the number of leftward 
!~ !(past) data points used, while nr is the number of rightward (future) data points, making 
!~ !the total number of data points used nl +nr+1. ld is the order of the derivative desired 
!~ !(e.g., ld = 0 for smoothed function). m is the order of the smoothing polynomial, also 
!~ !equal to the highest conserved moment; usual values are m = 2 or m = 4. 
!~ !--------------------------------------------------------------------------------------------
!~ INTEGER d,icode,imj,ipj,j,k,kk,mm,indx(MMAX+1) 
!~ real(KIND=long) fac,sum,a(MMAX+1,MMAX+1),b(MMAX+1)
!~   if(np.lt.nl+nr+1.or.nl.lt.0.or.nr.lt.0.or.ld.gt.m.or.m.gt.MMAX.or.nl+nr.lt.m) THEN
!~ 	  WRITE (*,*) ' Bad args in savgol.'
!~ 	  STOP
!~   END IF 
!~   do ipj=0,2*m        !Set up the normal equations of the desired leastsquares fit. 
!~     sum=0. 
!~     if(ipj.eq.0) sum=1. 
!~     do k=1,nr 
!~       sum=sum+dfloat(k)**ipj 
!~     end do 
!~     do k=1,nl 
!~       sum=sum+dfloat(-k)**ipj 
!~     end do 
!~     mm=min(ipj,2*m-ipj) 
!~     do imj=-mm,mm,2 
!~       a(1+(ipj+imj)/2,1+(ipj-imj)/2)=sum 
!~     end do 
!~   end do

!~   call ludcmp(a,m+1,MMAX+1,indx,d,icode)    !Solve them: LU decomposition. 

!~   do j=1,m+1 
!~     b(j)=0. 
!~   end do 
!~   b(ld+1)=1.      !Right-hand side vector is unit vector, depending on which derivative we want. 

!~   call lubksb(a,m+1,MMAX+1,indx,b)   !Backsubstitute, giving one row of the inverse matrix. 

!~   do kk=1,np                         !Zero the output array (it may be bigger than the number 
!~     c(kk)=0.                         !of coefficients).  
!~   end do 
!~   do k=-nl,nr                        !Each Savitzky-Golay coefficient is the dot product 
!~     sum=b(1)                         !of powers of an integer with the inverse matrix row. 
!~     fac=1. 
!~     do mm=1,m 
!~       fac=fac*k 
!~       sum=sum+b(mm+1)*fac 
!~     end do 
!~     kk=mod(np-k,np)+1                !Store in wrap-around order. 
!~     c(kk)=sum 
!~   end do
!~   return 
!~ END SUBROUTINE savgol

!~ !***************************************************************
!~ !* Given an N x N matrix A, this routine replaces it by the LU *
!~ !* decomposition of a rowwise permutation of itself. A and N   *
!~ !* are input. INDX is an output vector which records the row   *
!~ !* permutation effected by the partial pivoting; D is output   *
!~ !* as -1 or 1, depending on whether the number of row inter-   *
!~ !* changes was even or odd, respectively. This routine is used *
!~ !* in combination with LUBKSB to solve linear equations or to  *
!~ !* invert a matrix. Return code is 1, if matrix is singular.   *
!~ !***************************************************************
!~  Subroutine LUDCMP(A,N,NP,INDX,D,CODE)
!~  USE precision
!~  PARAMETER(NMAX=100,TINY=1E-12)

!~  real(KIND=long) AMAX,DUM, SUM, A(NP,NP),VV(NMAX)
!~  INTEGER CODE, D, INDX(N)

!~  D=1; CODE=0

!~  DO I=1,N
!~    AMAX=0.
!~    DO J=1,N
!~      IF (ABS(A(I,J)).GT.AMAX) AMAX=ABS(A(I,J))
!~    END DO ! j loop
!~    IF(AMAX.LT.TINY) THEN
!~      CODE = 1
!~      RETURN
!~    END IF
!~    VV(I) = 1. / AMAX
!~  END DO ! i loop

!~  DO J=1,N
!~    DO I=1,J-1
!~      SUM = A(I,J)
!~      DO K=1,I-1
!~        SUM = SUM - A(I,K)*A(K,J) 
!~      END DO ! k loop
!~      A(I,J) = SUM
!~    END DO ! i loop
!~    AMAX = 0.
!~    DO I=J,N
!~      SUM = A(I,J)
!~      DO K=1,J-1
!~        SUM = SUM - A(I,K)*A(K,J) 
!~      END DO ! k loop
!~      A(I,J) = SUM
!~      DUM = VV(I)*ABS(SUM)
!~      IF(DUM.GE.AMAX) THEN
!~        IMAX = I
!~        AMAX = DUM
!~      END IF
!~    END DO ! i loop  
   
!~    IF(J.NE.IMAX) THEN
!~      DO K=1,N
!~        DUM = A(IMAX,K)
!~        A(IMAX,K) = A(J,K)
!~        A(J,K) = DUM
!~      END DO ! k loop
!~      D = -D
!~      VV(IMAX) = VV(J)
!~    END IF

!~    INDX(J) = IMAX
!~    IF(ABS(A(J,J)) < TINY) A(J,J) = TINY

!~    IF(J.NE.N) THEN
!~      DUM = 1. / A(J,J)
!~      DO I=J+1,N
!~        A(I,J) = A(I,J)*DUM
!~      END DO ! i loop
!~    END IF 
!~  END DO ! j loop

!~  RETURN
!~  END Subroutine LUDCMP


!~ !******************************************************************
!~ !* Solves the set of N linear equations A . X = B.  Here A is     *
!~ !* input, not as the matrix A but rather as its LU decomposition, *
!~ !* determined by the routine LUDCMP. INDX is input as the permuta-*
!~ !* tion vector returned by LUDCMP. B is input as the right-hand   *
!~ !* side vector B, and returns with the solution vector X. A, N and*
!~ !* INDX are not modified by this routine and can be used for suc- *
!~ !* cessive calls with different right-hand sides. This routine is *
!~ !* also efficient for plain matrix inversion.                     *
!~ !******************************************************************
!~  Subroutine LUBKSB(A,N,NP,INDX,B)
!~  USE precision

!~  real(KIND=long)  SUM, A(NP,NP),B(N)
!~  INTEGER INDX(N)

!~  II = 0

!~  DO I=1,N
!~    LL = INDX(I)
!~    SUM = B(LL)
!~    B(LL) = B(I)
!~    IF(II.NE.0) THEN
!~      DO J=II,I-1
!~        SUM = SUM - A(I,J)*B(J)
!~      END DO ! j loop
!~    ELSE IF(SUM.NE.0.) THEN
!~      II = I
!~    END IF
!~    B(I) = SUM
!~  END DO ! i loop

!~  DO I=N,1,-1
!~    SUM = B(I)
!~    IF(I < N) THEN
!~      DO J=I+1,N
!~        SUM = SUM - A(I,J)*B(J)
!~      END DO ! j loop
!~    END IF
!~    B(I) = SUM / A(I,I)
!~  END DO ! i loop

!~  RETURN
!~  END Subroutine LUBKSB

!end of file tsavgol.f90
