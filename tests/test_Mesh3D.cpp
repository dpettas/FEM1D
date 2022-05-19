#include "Mesh3D.h"
#include <cstdlib>
#include <vector>
#include <cmath>

#include <fstream>
#include <iomanip>


void printNodes(const std::vector<FEM::Node3D*>& nodes)
{
  for (int i = 0; i < nodes.size(); ++i){
    std::cout << std::setprecision(3) << std::fixed
              << nodes.at(i)->getLabel() << " "
              << nodes.at(i)->getX() << " "
              << nodes.at(i)->getY() << " "
              << nodes.at(i)->getZ() << '\n';
  }

}




int main (int argc, char *argv[])
{
  FEM::Mesh3D mesh(10,20,25, FEM::Mesh3D::PolynomialOrder::Linear);

  // std::cout << mesh.getNumberOfElementsInX() << std::endl;
  // std::cout << mesh.getNumberOfElementsInY() << std::endl;
  // std::cout << mesh.getNumberOfElementsInZ() << std::endl;
  // std::cout << mesh.getNumberOfElements   () << std::endl;


  mesh.generateNodes();
  mesh.createconnectivity();

  mesh.toAsciiTeplot("test_.plt");


  return 0;
}

