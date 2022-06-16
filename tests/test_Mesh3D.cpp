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
              << nodes.at(i)->get()[0]<< " "
              << nodes.at(i)->get()[1]<< " "
              << nodes.at(i)->get()[2]<< '\n';
  }

}




int main (int argc, char *argv[])
{
  FEM::Mesh3D mesh(10,20,25);



  // mesh.generateNodes();
  // mesh.createconnectivity();

  mesh.toAsciiTeplot("test_.plt");


  return 0;
}

