#include "Mesh3D.h"
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
  FEM::Mesh3D mesh(1,1,1, FEM::Mesh3D::PolynomialOrder::Linear);


  // std::cout << mesh.getNumberOfElementsInX() << std::endl;
  // std::cout << mesh.getNumberOfElementsInY() << std::endl;
  // std::cout << mesh.getNumberOfElementsInZ() << std::endl;
  // std::cout << mesh.getNumberOfElements   () << std::endl;


  mesh.generateNodes();
  // mesh.createconnectivity();


  // const std::vector<FEM::Node3D>* nodes = &mesh.getNodes();
  auto plane_X_0   = [](const FEM::Node3D& n){ return std::abs(n.getX() - 0.0) <= 1e-8;};
  auto plane_X_0_5 = [](const FEM::Node3D& n){ return std::abs(n.getX() - 0.5) <= 1e-8;};
  auto plane_Y_0   = [](const FEM::Node3D& n){ return std::abs(n.getY() - 0.0) <= 1e-8;};
  auto plane_Y_0_5 = [](const FEM::Node3D& n){ return std::abs(n.getY() - 0.5) <= 1e-8;};
  auto plane_Z_0   = [](const FEM::Node3D& n){ return std::abs(n.getZ() - 0.0) <= 1e-8;};
  auto plane_Z_0_5 = [](const FEM::Node3D& n){ return std::abs(n.getZ() - 0.5) <= 1e-8;};
  auto all         = [](const FEM::Node3D& n){ return true;};





  std::ofstream file;
  file.open("nodes.dat");

  // {0,1,3,4,9,10,12,}
  printNodes(mesh.getNodesThatSatisfies(all  ));
  std::cout << std::endl;
  // printNodes(mesh.getNodesThatSatisfies(plane_X_0_5));
  // std::cout << std::endl;
  // printNodes(mesh.getNodesThatSatisfies(plane_Y_0  ));
  // std::cout << std::endl;
  // printNodes(mesh.getNodesThatSatisfies(plane_Y_0_5));



  file.close();

  return 0;
}

