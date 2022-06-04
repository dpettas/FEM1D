#include <iostream>
#include <cmath>
#include "Point1D.h"
#include "Node.h"

#include "Mesh3D.h"
#include "BasisFunctions/BasisFunction.h"
#include "BasisFunctions/LinearLagrange1D.h"
#include "src/BasisFunctions/LinearLagrange2D.h"



int main(){


  FEM::BFunction1D f1 ([](double x1)                       { return x1;});
  FEM::BFunction2D f2 ([](double x1, double x2)            { return x1*x2;});
  FEM::BFunction3D f3 ([](double x1, double x2, double x3) { return x1*x2*x3;});

  FEM::LinearLagrange1DBFunction l1d;
  FEM::LinearLagrange2DBFunction l2d;




  std::cout << "End\n";
  return 0;
}
