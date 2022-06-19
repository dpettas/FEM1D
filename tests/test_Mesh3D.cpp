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
  FEM::Mesh mesh(1,1,1);

  std::cout << mesh.getNumberOfNodes() << std::endl;
  std::cout << mesh.getNumberOfElements() << std::endl;
  std::cout << mesh.getNodeID(0,0,1) << std::endl;

  std::cout << std::fixed;
  for(int i = 0; i < mesh.getNumberOfNodes(); ++i)
    std::cout << mesh.getNode(i) << std::endl;




  return 0;
}

