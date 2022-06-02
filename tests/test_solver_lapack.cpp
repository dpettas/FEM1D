#include <cstdlib>
#include <iostream>
#include"lapacke.h"
#include "LinearAlgebra/solver_lapack.h"

int main()
{
    FEM::ALGEBRA::SolverLapack lapack;
    // note, to understand this part take a look in the MAN pages, at section of parameters.
    FEM::DenseMatrix mat = { {1,2,3}, 
                             {2,3,4}, 
                             {3,4,1} };
    FEM::Array       rhs = {-4, -1, -2};


    std::cout << mat << std::endl; 
    // std::cout << rhs << std::endl;
 
 

    lapack.factorize(mat);
    lapack.solve(mat,rhs);


    std::cout << "{" ;
    for (int i=0;i<rhs.size();i++)
        std::cout << rhs(i) << " ";
    std::cout << "}" << std::endl;
 
 
    std::cout << "program terminated." << std::endl;
    return 0;
}

