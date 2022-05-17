#include <iostream>
#include <iomanip>
#include <assert.h>
#include "Point3D.h"


int main (int argc, char *argv[])
{
  // Define the 1D version of the Point3D
  Point3D p1 { 1.0};
  Point3D p2 {-1.0};
  Point3D p3 { 0.0}; 

  std::cout << std::boolalpha;

  assert(p1 == Point3D( 1.0,0,0) );
  assert(p2 == Point3D(-1.0,0,0) );
  assert(p3 == Point3D( 0.0,0,0) );

  assert(p1 != p2);


  return 0;
}
