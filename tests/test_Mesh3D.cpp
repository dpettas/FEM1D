#include "Mesh3D.h"



int main (int argc, char *argv[])
{
  FEM::Mesh3D mesh(10,10,10, FEM::Mesh3D::PolynomialOrder::Quadratic);


  std::cout << mesh.getNumberOfElementsInX() << std::endl;
  std::cout << mesh.getNumberOfElementsInY() << std::endl;
  std::cout << mesh.getNumberOfElementsInZ() << std::endl;
  std::cout << mesh.getNumberOfElements   () << std::endl;


  mesh.generateNodes();

  std::vector<FEM::Node3D> nodes = mesh.getNodes();
  for (int i = 0; i < nodes.size(); ++i){
    std::cout << i << "   " << nodes[i] << std::endl;

  }

  return 0;
}

