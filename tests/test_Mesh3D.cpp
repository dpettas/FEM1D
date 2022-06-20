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

  mesh.scale(2,2,2).translate(-1.0, -1.0, -1.0);

  // std::cout << mesh.getNumberOfNodes() << std::endl;
  // std::cout << mesh.getNumberOfElements() << std::endl;
  // std::cout << mesh.getNodeID(0,0,1) << std::endl;
  std::cout << std::fixed;
  // std::cout << mesh.getNode(0) << std::endl;
  // std::cout << mesh.getNode(1) << std::endl;
  // std::cout << mesh.getNode(2) << std::endl;
  // std::cout << mesh.getNode(3) << std::endl;
  // std::cout << mesh.getNode(4) << std::endl;
  // std::cout << mesh.getNode(5) << std::endl;
  // std::cout << mesh.getNode(6) << std::endl;
  // std::cout << mesh.getNode(7) << std::endl;


  auto phi = [] (int i, FEM::Node3D& n) { return FEM::COLLECTION::linearLagrange3D.phi(i)(n); };



  FEM::Node3D n = mesh.getNode(0);
  std::cout << static_cast<FEM::Point3D>(n) << "    " << phi(0,n) << std::endl;





  return 0;
}

