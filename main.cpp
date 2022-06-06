#include <iostream>
#include <cmath>
#include <tuple>
// #include "Node.h"

// #include "Mesh3D.h"
#include "BasisFunctions/BasisFunction.h"
#include "BasisFunctions/BFunctionCollections.h"
#include "Integration/GPoint.h"
#include "Integration/GPointCollection.h"
#include "Integration/GPointCollections.h"
#include "math/functions.h"
#include "Point/Point.h"


int main(){

  FEM::Point d  = {0.0, 0.0, 1.0};


  std::cout << d << std::endl;
  // d.get()


  // FEM::Mesh3D mesh(5,5,5);
  //
  // FEM::Brick elm = mesh.getElement(2);
  //
  // std::cout << elm.getNode(0) << std::endl;





  std::cout << "End\n";
  return 0;
}
