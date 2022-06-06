#include <iostream>
#include <cmath>
#include <tuple>
#include "Point1D.h"
#include "Node.h"

#include "Mesh3D.h"
#include "BasisFunctions/BasisFunction.h"
#include "BasisFunctions/BFunctionCollections.h"
#include "Integration/GPoint.h"
#include "Integration/GPointCollection.h"
#include "Integration/GPointCollections.h"
#include "math/functions.h"



int main(){
  using FEM::COLLECTION::linearLagrange1D;
  using FEM::COLLECTION::linearLagrange2D;
  using FEM::COLLECTION::linearLagrange3D;



  std::cout << "****** linear Lagrange 1D ********\n";
  FEM::BFunctionCollection1D* l = &linearLagrange1D;
  std::cout << l->size() << std::endl;
  std::cout << l->phi(0)(-1.0) << "  "<< l->phi(0)(+1.0) << std::endl;
  std::cout << l->phi(1)(-1.0) << "  "<< l->phi(1)(+1.0) << std::endl;




  std::exit(0);






  std::cout << "End\n";
  return 0;
}
