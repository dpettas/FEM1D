#include <iostream>
#include <cmath>
#include "Point1D.h"
#include "Node.h"

#include "Mesh3D.h"
#include "BasisFunctions/BasisFunction.h"
#include "BasisFunctions/LinearLagrange1D.h"



int main(){


  FEM::BFunction1D f1 ([](double x1)                       { return x1;});
  FEM::BFunction2D f2 ([](double x1, double x2)            { return x1*x2;});
  FEM::BFunction3D f3 ([](double x1, double x2, double x3) { return x1*x2*x3;});

  FEM::LinearLagrangeBFunction l;

  auto dphidc = l.phi(1).derWithRespectTo(0);

  std::cout <<  dphidc(1.0) << std::endl;


  std::cout << "End\n";
  return 0;
}
