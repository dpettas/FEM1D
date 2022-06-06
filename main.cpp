#include <iostream>
#include <cmath>
#include <tuple>
#include "Point1D.h"
#include "Node.h"

#include "Mesh3D.h"
#include "BasisFunctions/BasisFunction.h"
#include "BasisFunctions/LinearLagrange1D.h"
#include "BasisFunctions/LinearLagrange2D.h"
#include "BasisFunctions/LinearLagrange3D.h"
#include "Integration/GPoint.h"
#include "Integration/GPointCollection.h"
#include "math/functions.h"




int main(){

  FEM::GPoint p (5.0/8.0,1.0,2.0);
  std::cout << "==========================\n";
  FEM::GPointCollection gp = { FEM::GPoint(1.0, 2.0, 3.0), 
                               FEM::GPoint(1.0, 2.0, 3.0)
  };
  std::cout << gp.size() << std::endl;
  std::cout << gp.get(0).get(1);
  std::cout << "==========================\n";


  std::exit(0);



  FEM::LinearLagrange1DBFunction l1d;
  FEM::LinearLagrange2DBFunction l2d;
  FEM::LinearLagrange3DBFunction l3d;

  auto phi = l3d.phi(0);

  double x = +1;  
  double y = -1;  
  double z = +1;  

  // point 0  (-1,-1,-1)
  // point 1  (+1,-1,-1)
  // point 2  (-1,+1,-1)
  // point 3  (+1,+1,-1)
  // point 4  (-1,-1,+1)
  // point 5  (+1,-1,+1)
  // point 6  (-1,+1,+1)
  // point 7  (+1,+1,+1)

  std::cout.precision(5);
  std::cout << std::fixed;
  
  std::cout << "0" << "  " << l3d.phi(0)(x,y,z) << std::endl;
  std::cout << "1" << "  " << l3d.phi(1)(x,y,z) << std::endl;
  std::cout << "2" << "  " << l3d.phi(2)(x,y,z) << std::endl;
  std::cout << "3" << "  " << l3d.phi(3)(x,y,z) << std::endl;
  std::cout << "4" << "  " << l3d.phi(4)(x,y,z) << std::endl;
  std::cout << "5" << "  " << l3d.phi(5)(x,y,z) << std::endl;
  std::cout << "6" << "  " << l3d.phi(6)(x,y,z) << std::endl;
  std::cout << "7" << "  " << l3d.phi(7)(x,y,z) << std::endl;



  std::cout << "End\n";
  return 0;
}
