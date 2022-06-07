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
#include "Point/operators.h"
#include "Node/Node.h"
#include "Node/functions.h"


int main(){

  auto p1  = FEM::makePoint(1.0, 2.0, 3.0);
  // FEM::Point p2  = {3.0, 4.0, 5.0};

  FEM::Node n1 (10, p1);
  FEM::Node n2 ( 9, p1);

// Check the Point class template
// Check the Node class template


  std::cout << std::boolalpha;
  std::cout << (n1 == n2) << std::endl;


  std::cout << "End\n";
  return 0;
}
