#ifndef _FEM_GPOINT_INCLUDED_
#define _FEM_GPOINT_INCLUDED_

#include "Point/Point.h"
#include "Point/operators.h"
#include <initializer_list>
#include <type_traits>
#include <exception>
#include <string>


namespace FEM 
{

  template < typename... Tv>
  class GPoint;
  
  using GPoint1D = GPoint<double>;
  using GPoint2D = GPoint<double, double>;
  using GPoint3D = GPoint<double, double, double>;


  template < typename... Tv>
  class GPoint : public Point<Tv...>
  {
    static_assert( (std::is_same_v <double, Tv> && ...) ,
        "All the arguments of the template should be doubles");


    public: 

      GPoint() = delete;
      GPoint(double weight, Tv... coords);
      GPoint(double weight, const Point<Tv...>& point);
      GPoint(const GPoint&  other);
      // GPoint(      GPoint&& other);

      GPoint& operator =  (const GPoint&  that);
      // GPoint& operator =  (      GPoint&& that);

      bool    operator == (const GPoint& other);
      bool    operator != (const GPoint& other);

      double  weight()   const;
    

    private: 

      double  _weight;
  };

  template<typename ...Tv> 
    GPoint<Tv...>::GPoint(double weight, Tv... coords): 
    _weight(weight)
    {
      int i = 0;
      ( (this->component(i++) = coords), ...  );
    }

  // template<typename ...Tv> 
  //   GPoint<Tv...>::GPoint(double weight, const Point<Tv...>& point): 
  //   Point <Tv...>::Point(point),
  //   _weight(weight)
  //   {}

   
  template<typename... Tv> 
    double GPoint<Tv...>::weight() const
    {
      return _weight;
    }

  template<typename... Tv> 
    GPoint<Tv...>::GPoint(const GPoint& other) : 
      // Point<Tv...>::Point(other), 
      _weight(weight)
    {}
  
  // template<typename... Tv> 
  //   GPoint<Tv...>::GPoint( GPoint&& other) : 
  //     Point<Tv...>::Point(other), 
  //     _weight(weight)
  //   {}

 template<typename... Tv> 
    GPoint<Tv...>& GPoint<Tv...>::operator = ( const GPoint& that)
    {
      if (this == &that)
        return *this;

      GPoint<Tv...>::operator=(that);
      _weight = that._weight;

      return *this;
    }
 
 // template<typename... Tv> 
 //    GPoint<Tv...>& GPoint<Tv...>::operator = ( GPoint&& that)
 //    {
 //      if (this == &that)
 //        return *this;
 //
 //      GPoint<Tv...>::operator=(that);
 //      _weight = that._weight;
 //
 //      return *this;
 //    }

  template<typename... Tv> 
    bool GPoint<Tv...>::operator == (const GPoint& other)
    {
      return _weight == other._weight && Point<Tv...>::operator==(other);
    }
  
  template<typename... Tv> 
    bool GPoint<Tv...>::operator != (const GPoint& other)
    {
      return !(GPoint<Tv...>::operator==(other));
    }

}
#endif
