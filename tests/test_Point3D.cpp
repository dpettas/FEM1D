#include <iostream>
#include <iomanip>
#include <assert.h>
#include "Point3D.h"


int main (int argc, char *argv[])
{
  // Define the 1D version of the Point3D
  FEM::Point3D p = {1.0,2.0,3.0};
  // FEM::Point3D p1 { 1.0};
  // FEM::Point3D p2 {-1.0};
  // FEM::Point3D p3 { 0.0}; 

  std::cout << std::boolalpha;
  std::cout << p << std::endl;

  // assert(p1 ==FEM::Point3D( 1.0,0,0) );
  // assert(p2 ==FEM::Point3D(-1.0,0,0) );
  // assert(p3 ==FEM::Point3D( 0.0,0,0) );

  // assert(p1 != p2);


  return 0;
}
