#include "Point1D.h"
#include <iostream>
#include <cassert>
#include <assert.h>



using std::cout;

int main (int argc, char *argv[])
{
  FEM::Point1D p;
  FEM::Point1D p1( 0.0);
  FEM::Point1D p2( 1.0);
  FEM::Point1D p3(-1.0);
  FEM::Point1D p4 = p3;
  FEM::Point1D* pp; 
  double a; 


  assert( p.numberOfDimensions() ==  1  );
  assert(*p .getCoordinates()    ==  0.0);
  assert(*p1.getCoordinates()    ==  0.0);
  assert(*p2.getCoordinates()    ==  1.0);
  assert(*p3.getCoordinates()    == -1.0);
  assert( p1.distanceFrom(p2)    ==  1.0);
  assert( p1.distanceFrom(p1)    ==  0.0);
  assert( p2.distanceFrom(p1)    ==  1.0);
  assert( p3.distanceFrom(p2)    ==  2.0);


  assert( *p4.getCoordinates()     == *p3.getCoordinates() );
  assert(  p4.numberOfDimensions() ==  p3.numberOfDimensions() );

  
  cout << "[PASSED]\n";
  return 0;
}
