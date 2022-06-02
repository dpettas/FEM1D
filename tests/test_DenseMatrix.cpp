#include <iostream>
#include <iomanip>
#include "LinearAlgebra/Array.h"
#include "LinearAlgebra/DenseMatrix.h"
#include "LinearAlgebra/Matrices.h"



// LAPACK test code

#include <iostream>
#include <vector>


using namespace std;

int main()
{

    FEM::Array a = {1,12,3,4};


    a({0,1,2}) = {9,1,1};

    FEM::DenseMatrix mat = { {1,2,3}, 
                             {4,5,6},
                             {7,8,9} };


    // mat({1,1}, {0,1}) = {  {10, 20}, 
    //                        {30, 40}
    //                     };

    std::cout << mat << std::endl;
    return(0);
}

