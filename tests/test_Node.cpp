#include <assert.h>
#include "Node.h"
#include <iostream>


int main (int argc, char *argv[])
{
  FEM::Node n1(0,0.0);
  FEM::Node n2(1,10.0);
 
  assert(n1.getNodeId() == 0.0);
  assert(*n1.getPoint()->getCoordinates() == 0.0);
  assert(n1.hasTheSameId(n2) == false);


  std::cout << "[PASSED]\n";
  return 0;
}
