#include "Integration/GPoint.h"
#include "Integration/functions.h"
#include <assert.h>
#include <cmath>
#include <iostream>



int main (int argc, char *argv[])
{
  FEM::GPoint p1 = {5.0/8.0, -10.0, 9.2, 9.3};
  FEM::GPoint p2 = {5.0/8.0, -10.0, 9.2, 9.3};

  assert( p1.weight() == 5.0/8.0);
  assert( p1.get()[0] == -10.0);
  assert( p1.get()[1] ==   9.2);
  assert( p1.get()[2] ==   9.3);


  assert(p1 == p2);


  FEM::GPoint p3 = {5.0/8.0, -5.0, 9.2, 9.3};
  FEM::GPoint p4 = {1.0/8.0, -5.0, 9.2, 9.3};
  assert(p3 != p4);

  FEM::GPoint p5 = {1.11111, -2.11111, 3.11111, 4.11111};
  p1 = std::move(p5);

  assert(p5.get()    == nullptr);
  assert(p1.get()[0] ==-2.11111 );
  assert(p1.get()[1] == 3.11111 );
  assert(p1.get()[2] == 4.11111 );
  assert(p1.weight() == 1.11111 );


  FEM::GPoint p6 = {1.22, -2.22, 3.22, 4.22};
  p1 = p6;
  assert(p1.get()[0] ==-2.22 );
  assert(p1.get()[1] == 3.22 );
  assert(p1.get()[2] == 4.22 );
  assert(p1.weight() == 1.22 );
  
  assert(p6.get()[0] ==-2.22 );
  assert(p6.get()[1] == 3.22 );
  assert(p6.get()[2] == 4.22 );
  assert(p6.weight() == 1.22 );
  
  std::cout << "[done]\n";
  return 0;
}
