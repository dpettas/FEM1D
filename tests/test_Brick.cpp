#include "Elements/Brick.h"
#include "Node3D.h"
#include "Mesh3D.h"
#include <iostream>

int main (int argc, char *argv[])
{
  FEM::Mesh3D mesh(1,1,1);

  FEM::Brick element;


  std::cout << element.getNumberOfNodes() << std::endl;
  
  return 0;
}
