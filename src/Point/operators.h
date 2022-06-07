#ifndef _FEM_POINT_OPERATORS_INCLUDED_ 
#define _FEM_POINT_OPERATORS_INCLUDED_ 

#include "Point/Point.h"

namespace FEM 
{



// Point<Ts...> makePoint(Ts... coords)
// the Ts should be double
template <typename...Ts> 
  Point<Ts...> makePoint(Ts... coords )
  {
    Point<Ts...> out;
    int i = 0;
    ( (out.component(i++) = coords), ...);

    return out;
  }


template <typename... Ts> 
  std::ostream& operator << (std::ostream& out, const Point<Ts...>& obj)
  {
    out << "("; 
    for(int i = 0; i < obj.size(); ++i)
    {
      out << obj.component(i);
      if ( i < (obj.size()-1) ) out << ",";
    }
    out << ")";
    return out;
  }

template <typename... Ts>
  Point<Ts...> operator * (const Point<Ts...>& p, double val)
  {
    Point<Ts...> out = p;

    for (int i = 0; i < p.size(); ++i)
      out.component(i) *= val;
    
    return out;
  }

template <typename... Ts>
  Point<Ts...> operator * (double val, const Point<Ts...>& p)
  {
    Point<Ts...> out = p;

    for (int i = 0; i < p.size(); ++i)
      out.component(i) *= val;
    
    return out;
  }

template <typename... Ts>
  Point<Ts...> operator / (const Point<Ts...>& p, double val)
  {
    Point<Ts...> out = p;

    for (int i = 0; i < p.size(); ++i)
      out.component(i) /= val;
    
    return out;
  }

template <typename... Ts>
  Point<Ts...> operator / (double val, const Point<Ts...>& p)
  {
    Point<Ts...> out = p;

    for (int i = 0; i < p.size(); ++i)
      out.component(i) /= val;
    
    return out;
  }
}
#endif
