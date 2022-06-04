#ifndef _FEM_BASISFUNCTION2D_INCLUDED_ 
#define _FEM_BASISFUNCTION2D_INCLUDED_ 

#include "BasisFunctions/exceptions.h"
#include <cstddef>
#include <functional>
#include <iostream>
#include <tuple>

namespace FEM 
{
template <typename ...Ts> class BasisFunction;

using BFunction1D = BasisFunction<double>;
using BFunction2D = BasisFunction<double,double>;
using BFunction3D = BasisFunction<double,double,double>;

template <typename ...Ts>
  class BasisFunction 
  {
    public: 
      using _func = std::function<double(Ts...)>;

      void set_diff_tolerance(double eps);


      BasisFunction() = delete;
      BasisFunction(_func basisFunction );
      BasisFunction(const BasisFunction& other);

      BasisFunction& operator = (const BasisFunction& that);
      double operator () (Ts...);

      constexpr int dimensionality() const;
      _func derWithRespectTo(int i);

    private: 

      double _eps = 1e-6;
      _func _basisFunction;

  };


  // Member Definition 
  template<typename ...Ts>
  void BasisFunction<Ts...>::set_diff_tolerance(double eps)
  {
    _eps = eps;
  }

  template<typename ...Ts>
  BasisFunction<Ts...>::BasisFunction(_func basisFunction):
    _basisFunction(basisFunction)
  {}

  template<typename ...Ts> 
  BasisFunction<Ts...>::BasisFunction(const BasisFunction<Ts...>& other):
  _basisFunction(other._basisFunction)
  {}

  template<typename ...Ts>
  double BasisFunction<Ts...>::operator()(Ts... args) 
  { 
    return _basisFunction(args...);
  }

  template<typename ...Ts> 
    constexpr int BasisFunction<Ts...>::dimensionality() const
    {
      return sizeof...(Ts);
    }

  template<typename ...Ts>
    std::function<double(Ts...)>  
    BasisFunction<Ts...>::derWithRespectTo(int i)
    {

      throw FEM::NotGerericImplementation("The function derWithRespectTo is not implemented in generic type.");
    }
}

#endif 
