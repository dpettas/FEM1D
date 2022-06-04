#include <iostream>
#include <cmath>
#include "Point1D.h"
#include "Node.h"

#include "Mesh3D.h"
#include "BasisFunctions/BasisFunction1D.h"



int main(){


  FEM::BasisFunction1D func ([](double x1) { return x1*x1;});
  
  auto df = func.dx1();

  std::cout << func(3) << std::endl;
  std::cout << df(3) << std::endl;

  FEM::Mesh3D mesh(5,5,5);

  mesh.toAsciiTeplot("fromMain.plt");




  std::cout << "End\n";
  return 0;
}
