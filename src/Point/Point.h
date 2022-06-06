#ifndef _FEM_POINT_INCLUDED_
#define _FEM_POINT_INCLUDED_ 

#include <initializer_list>
#include <type_traits>
#include <iostream>

namespace FEM 
{
  template <typename... Ts> 
    class Point; 

  using Point1D = Point<double>;
  using Point2D = Point<double,double>;
  using Point3D = Point<double,double,double>;



  template <typename... Ts>
  class Point 
  {
    public:

      Point(Ts... coords);
      ~Point();

      Point(const Point<Ts...>&   other);
      Point(      Point<Ts...>&&  other);

      Point& operator = (const Point&  that);
      Point& operator = (      Point&& that);

      bool   operator== (const Point& other);


      int size()                     const;
      const double* get()            const;
      const double& component(int i) const;
      double&       component(int i);

    private:
      double* _coords = nullptr;
  };


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
  Point<Ts...>::Point(Ts... coords)
  {
    _coords = new double [sizeof...(Ts)];

    int i = 0;
    ( (_coords[i++]= coords)  , ...);
  }


template <typename... Ts>
  Point<Ts...>::Point(const Point<Ts...>& other)
  {
    if (!_coords) 
      delete [] _coords;

    _coords = new double [other.size()];
    for(int i = 0; i < size(); ++i)
      _coords[i] = other._coords[i]; 
  }

template <typename... Ts>
  Point<Ts...>::Point( Point<Ts...>&& other)
  {
    if (!_coords) 
      delete [] _coords;

    _coords = other._coords;
    delete [] other._coords;
  }

template <typename... Ts> 
  Point<Ts...>& Point<Ts...>::operator=(const Point& that)
  {
    if (this == &that)
      return *this;

    if (!_coords) 
      delete [] _coords;

    _coords = new double [that.size()];
    for(int i = 0; i < size(); ++i)
      _coords[i] = that._coords[i]; 

    return *this;
  }

template <typename... Ts> 
  Point<Ts...>& Point<Ts...>::operator=( Point<Ts...>&& that)
  {
    if (this == &that)
      return *this;

    if (!_coords) 
      delete [] _coords;

    _coords = that._coords;
    delete [] that._coords;

    return *this;
  }


template <typename... Ts>
  const double* Point<Ts...>::get() const
  {
    return _coords;
  }

template <typename... Ts>
  const double& Point<Ts...>::component(int i) const
  {
    return _coords[i];
  }

template <typename... Ts>
  double& Point<Ts...>::component(int i)
  {
    return _coords[i];
  }

template <typename... Ts> 
  Point<Ts...>::~Point()
  {
    if (!_coords) delete [] _coords;
  }

template <typename... Ts> 
  int Point<Ts...>::size() const
  {
    return sizeof...(Ts);
  }


}






#endif
