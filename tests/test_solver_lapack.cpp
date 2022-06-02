#include <cstdlib>
#include <iostream>
#include"lapacke.h"
#include "LinearAlgebra/solver_lapack.h"

int main()
{
    FEM::ALGEBRA::SolverLapack lapack;
    // note, to understand this part take a look in the MAN pages, at section of parameters.
    FEM::DenseMatrix mat = { {1,2,-1}, 
                             {2,2,2},
                             {1,-2,2}};
    FEM::Array       rhs = {2, 12, 5};





 
 

    lapack.factorize(mat);
    lapack.solve(mat,rhs);


    std::cout << "{" ;
    for (int i=0;i<rhs.size();i++)
        std::cout << rhs(i) << " ";
    std::cout << "}" << std::endl;
 
 
    std::cout << "program terminated." << std::endl;
    return 0;
}

