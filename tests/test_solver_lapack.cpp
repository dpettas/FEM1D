#include <cstdlib>
#include <iostream>
#include"lapacke.h"
#include "LinearAlgebra/solver_lapack.h"

int main()
{
    FEM::ALGEBRA::SolverLapack lapack;
    // note, to understand this part take a look in the MAN pages, at section of parameters.
    int     N = 3;
 
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

    lapack.factorize(N,N,A);
    lapack.solve(N,A,B);
    std::cout << "{" ;
    for (int i=0;i<N;i++)
        std::cout << B[i] << " ";
    std::cout << "}" << std::endl;
    std::exit(0);
 
 
    std::cout << "program terminated." << std::endl;
    return 0;
}

