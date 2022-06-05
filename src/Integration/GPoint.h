#ifndef _FEM_GPOINT_INCLUDED_
#define _FEM_GPOINT_INCLUDED_

#include <iostream>
#include <type_traits>

namespace FEM 
{
  template < typename... Tv>
  class GPoint;
  
  using GPoint1D = GPoint<double>;
  using GPoint2D = GPoint<double, double>;
  using GPoint3D = GPoint<double, double, double>;


  template < typename... Tv>
  class GPoint 
  {
    static_assert( (std::is_same_v <double, Tv> && ...) ,
        "All the arguments of the template should be doubles");


    public: 

      GPoint() = delete;
      GPoint(double weight, Tv...);

      constexpr double* get();
      constexpr double  weight();
      constexpr int     size() const;

    private: 

      double  _weight;
      double coors[sizeof...(Tv)];
  };


  

  template<typename ...Tv> 
    GPoint<Tv...>::GPoint(double weight, Tv ... coords) 
    {
      _weight = weight;

      int j = 0; 
      ( (coors[j++] = coords), ...);
    }

  template<typename ...Tv> 
    constexpr int GPoint<Tv...>::size() const 
    {
      return sizeof...(Tv);
    }

  template<typename... Tv> 
    constexpr double* GPoint<Tv...>::get() 
    {
      return coors;
    }

  template<typename... Tv> 
    constexpr double GPoint<Tv...>::weight() 
    {
      return _weight;
    }




}
#endif
