#include <iostream>
#include"lapacke.h"


int main()
{
    // note, to understand this part take a look in the MAN pages, at section of parameters.
    char    TRANS = 'N';
    int     INFO=3;
    int     LDA = 3;
    int     LDB = 3;
    int     N = 3;
    int     NRHS = 1;
    int     IPIV[3] ;
 
    double  A[9] =
    {
    1, 2, 3,
    2, 3, 4,
    3, 4, 1
    };
 
    double B[3] =
    {
    -4,
    -1,
    -2
    };
// end of declarations
 
    std::cout << "compute the LU factorization..."  << std::endl;
    //void LAPACK_dgetrf( lapack_int* m, lapack_int* n, double* a, lapack_int* lda, lapack_int* ipiv, lapack_int *info );
    LAPACK_dgetrf(&N,&N,A,&LDA,IPIV,&INFO);
 
    // checks INFO, if INFO != 0 something goes wrong, for more information see the MAN page of dgetrf.
    if(INFO)
    {
      std::cout << "an error occured : "<< INFO << std::endl;
    }else{
      std::cout << "solving the system..."<< std::endl;
        // void LAPACK_dgetrs( char* trans, lapack_int* n, lapack_int* nrhs, const double* a, lapack_int* lda, const lapack_int* ipiv,double* b, lapack_int* ldb, lapack_int *info );
        dgetrs_(&TRANS,&N,&NRHS,A,&LDA,IPIV,B,&LDB,&INFO);
        if(INFO)
        {
            // checks INFO, if INFO != 0 something goes wrong, for more information see the MAN page of dgetrs.
          std::cout << "an error occured : "<< INFO << std::endl;
        }else{
          std::cout << "print the result : {";
            int i;
            for (i=0;i<N;i++)
            {
              std::cout << B[i] << " ";
            }
            std::cout << "}" << std::endl;
        }
    }
 
    std::cout << "program terminated." << std::endl;
    return 0;
}

