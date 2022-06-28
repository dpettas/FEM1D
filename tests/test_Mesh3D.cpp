#include "Mesh/Mesh.h"
#include "Node/Node.h"
#include "Node/functions.h"
#include "BasisFunctions/BFunctionCollections.h"
#include <cstdlib>
#include <vector>
#include <cmath>

#include <fstream>
#include <iomanip>

void showBFunctions(const FEM::Node3D& n)
{
  auto phi = [] (int i, const FEM::Node3D& n) { return FEM::COLLECTION::linearLagrange3D.phi(i)(n); };
  
  std::cout <<  "  0.  " << phi(0,n) << "  ";
  std::cout <<  "  1.  " << phi(1,n) << "  ";
  std::cout <<  "  2.  " << phi(2,n) << "  ";
  std::cout <<  "  3.  " << phi(3,n) << "  ";
  std::cout <<  "  4.  " << phi(4,n) << "  ";
  std::cout <<  "  5.  " << phi(5,n) << "  ";
  std::cout <<  "  6.  " << phi(6,n) << "  ";
  std::cout <<  "  7.  " << phi(7,n) << std::endl;
}



int main (int argc, char *argv[])
{
  FEM::Mesh mesh(1,1,1);



  mesh.scale(2,2,2).translate(-1.0, -1.0, -1.0);

  std::cout << mesh.getElement(0).centroid() << std::endl;

  FEM::Mesh cmesh = mesh;
  cmesh.toAsciiTecplot("cmesh.plt");


  // std::cout << mesh.getNumberOfNodes() << std::endl;
  // std::cout << mesh.getNumberOfElements() << std::endl;
  // std::cout << mesh.getNodeID(0,0,1) << std::endl;
  std::cout << std::fixed;
  showBFunctions(mesh.getElement(0).getNode(0));
  showBFunctions(mesh.getElement(0).getNode(1));
  showBFunctions(mesh.getElement(0).getNode(2));
  showBFunctions(mesh.getElement(0).getNode(3));
  showBFunctions(mesh.getElement(0).getNode(4));
  showBFunctions(mesh.getElement(0).getNode(5));
  showBFunctions(mesh.getElement(0).getNode(6));
  showBFunctions(mesh.getElement(0).getNode(7));










  return 0;
}

