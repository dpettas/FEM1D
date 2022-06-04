#include <iostream>
#include <cmath>
#include "Point1D.h"
#include "Node.h"

#include "Mesh3D.h"
#include "BasisFunctions/BasisFunction1D.h"
#include "BasisFunctions/BasisFunction2D.h"



int main(){


  FEM::BasisFunction<double> func ([](double x1) { return x1*x1;});
  FEM::BasisFunction<double,double> f2 ([](double x1, double x2) { return x1*x2;});
  FEM::BasisFunction<double,double> f2 ([](double x1, double x2) { return x1*x2;});

  auto df2 = f2.derWithRespectTo(1);

  std::cout << f2 (2.0, 3.0) << std::endl;
  std::cout << df2(2.0, 3.0) << std::endl;
  // std::cout << func.derWithRespectTo(0)(1) << std::endl;





  std::cout << "End\n";
  return 0;
}
