#ifndef _FEM_GPOINT_INCLUDED_
#define _FEM_GPOINT_INCLUDED_

#include <iostream>
#include <type_traits>

namespace FEM 
{




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
      std::cout << "Hi" << std::endl;
    }

}
#endif
