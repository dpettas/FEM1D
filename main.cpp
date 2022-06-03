#include <iostream>
#include "Legacy/element_module.h"

LEGACY::element_module element_module;

int main()
{

  element_module.discretization_data();

  std::cout << element_module.nodtol << std::endl;
  
  


  std::cout << "End\n";
  return 0;
}
