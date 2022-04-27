#include <assert.h>
#include "Node.h"
#include <iostream>
#include <string>
#include <vector>

template<typename T> 
int info(T A){ return sizeof(A);}


int main (int argc, char *argv[])
{


  FEM::Node n1(0,0.0);
  FEM::Node n2(1,10.0);

  std::cout << n1.getNodeId() << std::endl;
  std::cout << n2.getNodeId() << std::endl;

  assert(n1.getNodeId() == 0.0);
  assert(*n1.getPoint()->getCoordinates() == 0.0);
  assert(n1.hasTheSameId(n2) == false);



  std::cout << "[PASSED]\n";
  return 0;
}
