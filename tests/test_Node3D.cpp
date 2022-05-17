#include <iostream>
#include <assert.h>
#include "Node3D.h"

using  FEM::Node3D;

int main (int argc, char *argv[])
{
  Node3D n1;
  
  assert(n1 == Node3D(-1,0,0,0));

  std::cout << "[PASSED]\n";
  return 0;
}
