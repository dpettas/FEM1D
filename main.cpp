#include <iostream>
#include <cmath>
#include "Point1D.h"
#include "Node.h"

#include "Mesh3D.h"
#include "BasisFunctions/BasisFunction.h"



int main(){


  FEM::BFunction1D f1 ([](double x1)                       { return x1*x1;});
  FEM::BFunction2D f2 ([](double x1, double x2)            { return x1*x1;});
  FEM::BFunction3D f3 ([](double x1, double x2, double x3) { return x1*x1;});







  std::cout << "End\n";
  return 0;
}
