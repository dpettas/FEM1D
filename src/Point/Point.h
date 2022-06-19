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

      Point() = delete;
      ~Point();

      Point(const Ts... coords);
      Point(const Point<Ts...>&   other);
      Point(      Point<Ts...>&&  other);

      Point& operator = (const Point&  that);
      Point& operator = (      Point&& that);


      Point  operator+ (const Point& that);
      Point  operator- (const Point& that);

      Point& operator+=(const Point& that);
      Point& operator-=(const Point& that);
      Point& operator*=(const double& val);
      Point& operator/=(const double& val);

      bool   operator== (const Point& other) const;
      bool   operator!= (const Point& other) const;


      int size()                     const;
      const double* get()            const;
      const double& component(int i) const;
      double&       component(int i);

    private:
      double* _coords = nullptr;
  };


template <typename... Ts>
  Point<Ts...>::Point(const Ts... coords)
  {
    _coords = new double [sizeof...(Ts)];

    int i = 0; 
    ( (_coords[i++] = coords), ...  );
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
    other._coords = nullptr;
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

    that._coords = nullptr;

    return *this;
  }

template <typename... Ts> 
  Point<Ts...> Point<Ts...>::operator + (const Point<Ts...>& that)
  {
    Point<Ts...> out = *this;

    for (int i=0; i<size(); ++i)
      out._coords[i] += that._coords[i];

    return out;
  }

template <typename... Ts> 
  Point<Ts...> Point<Ts...>::operator - (const Point<Ts...>& that)
  {
    Point<Ts...> out = *this;;

    for (int i=0; i<size(); ++i)
      out._coords[i] -= that._coords[i];

    return out;
  }


template <typename... Ts> 
  Point<Ts...>& Point<Ts...>::operator +=(const Point<Ts...>& that)
  {

    for (int i=0; i<size(); ++i)
      _coords[i] += that._coords[i];

    return *this;
  }

template <typename... Ts> 
  Point<Ts...>& Point<Ts...>::operator -=(const Point<Ts...>& that)
  {

    for (int i=0; i<size(); ++i)
      _coords[i] -= that._coords[i];

    return *this;
  }

template <typename... Ts> 
  Point<Ts...>& Point<Ts...>::operator *=(const double& val)
  {

    for (int i=0; i<size(); ++i)
      _coords[i] *= val;

    return *this;
  }

template <typename... Ts> 
  Point<Ts...>& Point<Ts...>::operator /=(const double& val)
  {

    for (int i=0; i<size(); ++i)
      _coords[i] /= val;

    return *this;
  }


template <typename... Ts> 
  bool Point<Ts...>::operator == (const Point<Ts...>& other) const
  {
    bool out = true;

    if (!other._coords && !_coords)
      return true;

    if (!other._coords &&  _coords)
      return false;

    for (int i=0; i<size(); ++i)
      out = out && ( std::abs(_coords[i] - other._coords[i]) <= 1e-8 );

    return out;
  }


template <typename... Ts> 
  bool Point<Ts...>::operator != (const Point<Ts...>& other) const
  {
    return !operator==(other);
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
