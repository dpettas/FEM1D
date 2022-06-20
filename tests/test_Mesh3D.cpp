#include "Mesh/Mesh.h"
#include "Node/Node.h"
#include "Node/functions.h"
#include "BasisFunctions/BFunctionCollections.h"
#include <cstdlib>
#include <vector>
#include <cmath>

#include <fstream>
#include <iomanip>





int main (int argc, char *argv[])
{
  FEM::Mesh mesh(1,1,1);

  // std::cout << mesh.getNumberOfNodes() << std::endl;
  // std::cout << mesh.getNumberOfElements() << std::endl;
  // std::cout << mesh.getNodeID(0,0,1) << std::endl;

  FEM::Node3D n = mesh.getNode(1);

  auto phi = [] (int i, FEM::Node3D& n) { return FEM::COLLECTION::linearLagrange3D.phi(i)(n); };



  std::cout << std::fixed;
  std::cout << static_cast<FEM::Point3D>(n) << "    " << phi(7,n) << std::endl;





  return 0;
}

