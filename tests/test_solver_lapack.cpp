#include <cstdlib>
#include <iostream>
#include"lapacke.h"
#include "LinearAlgebra/solver_lapack.h"

int main()
{
    FEM::ALGEBRA::SolverLapack lapack;
    // note, to understand this part take a look in the MAN pages, at section of parameters.
    int     N = 3;
    FEM::DenseMatrix mat(3,3);
    FEM::Array       rhs(3);

    mat(0,0) = 1.0;
    mat(0,1) = 2.0; 
    mat(0,2) = 3.0;

    mat(1,0) = 2.0;
    mat(1,1) = 3.0; 
    mat(1,2) = 4.0;

    mat(2,0) = 3.0;
    mat(2,1) = 4.0; 
    mat(2,2) = 1.0;

    rhs(0)   = -4;
    rhs(1)   = -1;
    rhs(2)   = -2;

    std::cout << mat << std::endl; 
    // std::cout << rhs << std::endl;
 
 

    lapack.factorize(mat);
    lapack.solve(mat,rhs);


    std::cout << "{" ;
    for (int i=0;i<N;i++)
        std::cout << rhs(i) << " ";
    std::cout << "}" << std::endl;
 
 
    std::cout << "program terminated." << std::endl;
    return 0;
}

