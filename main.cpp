#include <iostream>
#include <cmath>
#include "Point1D.h"
#include "Node.h"

#include "Mesh3D.h"
#include "BasisFunctions/BasisFunction.h"
#include "BasisFunctions/LinearLagrange1D.h"
#include "BasisFunctions/LinearLagrange2D.h"
#include "BasisFunctions/LinearLagrange3D.h"





int main(){


  FEM::BFunction1D f1 ([](double x1)                       { return x1;});
  FEM::BFunction2D f2 ([](double x1, double x2)            { return x1*x2;});
  FEM::BFunction3D f3 ([](double x1, double x2, double x3) { return x1*x2*x3;});

  FEM::LinearLagrange1DBFunction l1d;
  FEM::LinearLagrange2DBFunction l2d;
  FEM::LinearLagrange3DBFunction l3d;

  auto phi = l3d.phi(0);

  std::cout << l3d.phi(3)(0.00,0.5,0.5) << std::endl;



  std::cout << "End\n";
  return 0;
}
