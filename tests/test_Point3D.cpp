#include <iostream>
#include <iomanip>
#include <assert.h>
#include <cmath>
#include "Point3D.h"


int main (int argc, char *argv[])
{
  // Define the 1D version of the Point3D
  FEM::Point3D csys1 = {0.0,0.0,0.0};
  FEM::Point3D csys2 = {0.0,0.0,0.0};

  // equality
  assert(csys1 == csys2);
  assert(csys1 == FEM::Point3D(0.0, 0.0, 0.0));

  // Check setters
  FEM::Point3D p;
  assert(p == FEM::Point3D(0.0, 0.0, 0.0));

  p.setX(1.0);
  assert(p == FEM::Point3D(1.0, 0.0, 0.0));
  p.setY(2.0);
  assert(p == FEM::Point3D(1.0, 2.0, 0.0));
  p.setZ(4.0);
  assert(p == FEM::Point3D(1.0, 2.0, 4.0));

  // Check getters
  assert(p.getX() == 1.0);
  assert(p.getY() == 2.0); 
  assert(p.getZ() == 4.0);

  const FEM::Point3D p1{10,20,40};
  assert(p1.getX() == 10.0);
  assert(p1.getY() == 20.0); 
  assert(p1.getZ() == 40.0);


  // Check arithmetic operations
  const FEM::Point3D p2 = p1 + FEM::Point3D(40,20,10);
  assert(p2 == FEM::Point3D(50,40,50));

  const FEM::Point3D p3 = FEM::Point3D(1,2,3) - FEM::Point3D(3,2,1);
  assert(p3 == FEM::Point3D(-2,0,2));

  // Check boolean operators
  assert(p3 != csys1);


  // check functions 
  assert( p3.distanceFrom(csys1) == std::sqrt(8.0));
  assert( p3.distanceFrom({0.0,0.0,0.0}) == std::sqrt(8.0));
  assert( p3.distanceFrom(0.0,0.0,0.0) == std::sqrt(8.0));

  assert( p3.distanceFrom(-2,0,0) == std::sqrt(4.0));
  assert( p3.distanceFrom(FEM::Point3D{-2,0,0}) == std::sqrt(4.0));




  std::cout << "[done]\n";
  return 0;
}
