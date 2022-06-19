#include "Mesh/Mesh.h"
#include "Node/Node.h"
#include "Node/functions.h"
#include <cstdlib>
#include <vector>
#include <cmath>

#include <fstream>
#include <iomanip>





int main (int argc, char *argv[])
{
  FEM::Mesh mesh(3,3,2);

  std::cout << mesh.getNumberOfNodes() << std::endl;
  std::cout << mesh.getNumberOfElements() << std::endl;
  std::cout << mesh.getNodeID(0,0,1) << std::endl;


  for (const FEM::Node3D n : mesh.getNodes())
    std::cout << n << std::endl;




  return 0;
}

