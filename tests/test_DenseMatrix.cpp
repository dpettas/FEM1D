#include <iostream>
#include <iomanip>
#include "LinearAlgebra/DenseMatrix.h"


int main (int argc, char *argv[])
{
  FEM::DenseMatrix mat(3,5,1.0); 

  mat(10,0) = 10.0;
  std::cout << mat << std::endl;

  // mat.value(1,2) = 10;
  // mat.value(0,0) =  0;
  // mat.value(0,1) =  2;
  // mat.value(0,2) =  3;
  // mat.value(2,4) =  3;
  // std::cout << std::setprecision(4) << std::fixed;
  // std::cout << mat << std::endl;
 

  return 0;
}
