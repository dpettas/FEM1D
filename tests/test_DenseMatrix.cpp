#include <iostream>
#include <iomanip>
#include "LinearAlgebra/DenseMatrix.h"
#include "LinearAlgebra/Matrices.h"



// LAPACK test code

#include <iostream>
#include <vector>


using namespace std;

int main()
{

    FEM::DenseMatrix mat = { {1,2,3}, 
                             {4,5,6},
                             {7,8,9} };



    std::cout << mat << std::endl;
    return(0);
}

