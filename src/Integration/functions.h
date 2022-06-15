#ifndef _FEM_GPOINT_FUNCTIONS_INCLUDED_
#define _FEM_GPOINT_FUNCTIONS_INCLUDED_ 
#include "Integration/GPoint.h"
#include <iostream>

FEM::GPoint2D makeGPoint( FEM::GPoint1D gs1, FEM::GPoint1D gs2 );
FEM::GPoint3D makeGPoint( FEM::GPoint1D gs1, FEM::GPoint1D gs2, FEM::GPoint1D gs3 );



template <typename... Ts>
std::ostream& operator << (std::ostream& out, const FEM::GPoint<Ts...>& obj)
{
  FEM::Point p = obj; // obj slicing

  std::cout << "point : " << p << ", weight  : " << obj.weight();
  return out;
}

#endif
