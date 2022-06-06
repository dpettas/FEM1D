#ifndef _FEM_GPOINT_INCLUDED_
#define _FEM_GPOINT_INCLUDED_

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
  class GPoint 
  {
    static_assert( (std::is_same_v <double, Tv> && ...) ,
        "All the arguments of the template should be doubles");


    public: 

      GPoint() = delete;
      GPoint(double weight, Tv...);
      ~GPoint();

      double  get(int i) const;
      double* get()      const;
      double  weight()   const;
      constexpr int     size() const;

    private: 

      double  _weight;
      double* coors = nullptr;
  };


  

  template<typename ...Tv> 
    GPoint<Tv...>::GPoint(double weight, Tv... coords) 
    {
      _weight = weight;
      coors = new double [sizeof...(Tv)];

      int j = 0; 
      ( (coors[j++] = coords), ...);
    }

  template<typename... Tv> 
   GPoint<Tv...>::~GPoint() 
   {
    if(!coors) delete [] coors;
   }
  

  template<typename ...Tv> 
    constexpr int GPoint<Tv...>::size() const 
    {
      return sizeof...(Tv);
    }

  template<typename... Tv> 
    double GPoint<Tv...>::get(int i)  const
    {
      return coors[i];
    }
  
  template<typename... Tv> 
    double* GPoint<Tv...>::get()  const
    {
      return coors;
    }

  template<typename... Tv> 
    double GPoint<Tv...>::weight() const
    {
      return _weight;
    }




}
#endif
