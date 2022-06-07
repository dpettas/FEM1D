#include <iostream>
#include <assert.h>
#include "Point.h"


int main (int argc, char *argv[])
{
  FEM::Point   p0 = FEM::makePoint(0.0,0.0,0.0);
  FEM::Point   p1 = FEM::makePoint(1.0,0.0,0.0);

  // size 
  assert(p0.size() == 3);

  // Check Operator !=
  assert( p0 != p1 );
 
  // copy assignment
  p0 = p1;
  // Operator == 
  assert(p0 == p1);

  // move assignment
  p0 = std::move(p1);
  assert(p0 != p1);

  FEM::Point a1   = FEM::makePoint(1.0, -1.0, -1.0);
  FEM::Point a2   = FEM::makePoint(2.0, +1.0, +1.0);
  FEM::Point res_p= FEM::makePoint(3.0,  0.0,  0.0);
  FEM::Point res_m= FEM::makePoint(1.0,  2.0,  2.0);
 
  // addition 
  assert( a1 + a2 == res_p);
  // subtraction 
  assert( a2 - a1 == res_m);


  // multiplucation
  FEM::Point m1   = FEM::makePoint(1.5,2.0,0.25);
  FEM::Point res3 = FEM::makePoint(3.0,4.0,0.50);

  assert( 2.0 * m1 == res3    );
  assert( 2.0 * m1 == m1 * 2.0);

  // division
  FEM::Point d1   = FEM::makePoint(2.0,3.0,0.25);
  FEM::Point res4 = FEM::makePoint(1.0,1.5,0.125);

  assert( d1/2.0 == res4 );

  
  return 0;
}
