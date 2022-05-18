#include "Mesh3D.h"
#include <vector>

#include <fstream>
#include <iomanip>



int main (int argc, char *argv[])
{
  FEM::Mesh3D mesh(10,10,10, FEM::Mesh3D::PolynomialOrder::Quadratic);


  std::cout << mesh.getNumberOfElementsInX() << std::endl;
  std::cout << mesh.getNumberOfElementsInY() << std::endl;
  std::cout << mesh.getNumberOfElementsInZ() << std::endl;
  std::cout << mesh.getNumberOfElements   () << std::endl;


  mesh.generateNodes();


  const std::vector<FEM::Node3D>* nodes = &mesh.getNodes();


  std::ofstream file;
  file.open("nodes.dat");

  
  for (int i = 0; i < nodes->size(); ++i){
    file      << std::setprecision(10) << std::fixed 
              << nodes->at(i).getX() << " "
              << nodes->at(i).getY() << " "
              << nodes->at(i).getZ() << '\n';

  }
  file.close();

  return 0;
}

