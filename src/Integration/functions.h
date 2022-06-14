#ifndef _FEM_GPOINT_FUNCTIONS_INCLUDED_
#define _FEM_GPOINT_FUNCTIONS_INCLUDED_ 
#include "Integration/GPoint.h"
#include <iostream>

template <typename... Ts>
std::ostream& operator << (std::ostream& out, const FEM::GPoint<Ts...>& obj)
{
  FEM::Point p = obj; // obj slicing

  std::cout << "point : " << p << ", weight  : " << obj.weight();
  return out;
}

#endif
