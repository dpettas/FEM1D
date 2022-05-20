#include <iostream>
#include "Integration/GaussPoint1D.h"


int main (int argc, char *argv[])
{
  
  FEM::GaussPoint1D gs(10.0, 11.0);
 
  auto [v1,v2] = gs.get();
  std::cout << v1 << std::endl;
  std::cout << v2 << std::endl;
  return 0;
}
