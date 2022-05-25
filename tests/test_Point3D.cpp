#include <iostream>
#include <iomanip>
#include <assert.h>
#include "Point3D.h"


int main (int argc, char *argv[])
{
  // Define the 1D version of the Point3D
  FEM::Point3D p1 = {1.0,2.0,3.0};
  FEM::Point3D p2 = {1.0,2.0,3.0};

  std::cout << std::boolalpha;
  std::cout << std::fixed;
  std::cout << p1 << std::endl;
  std::cout << p2 << std::endl;
  std::cout << p1 + p2 << std::endl;
  std::cout << (p1 == p2) << std::endl;



  return 0;
}
