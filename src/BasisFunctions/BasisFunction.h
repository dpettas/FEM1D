#ifndef _FEM_BASISFUNCTION2D_INCLUDED_ 
#define _FEM_BASISFUNCTION2D_INCLUDED_ 

#include "BasisFunctions/exceptions.h"
#include "Point/Point.h"
#include "exceptions/exceptions.h"
#include <cstddef>
#include <functional>
#include <iostream>
#include <tuple>




namespace FEM 
{
template <typename ...Ts> class BFunction;


using BFunction1D = BFunction<double>;
using BFunction2D = BFunction<double,double>;
using BFunction3D = BFunction<double,double,double>;



template <typename ...Ts>
  class BFunction 
  {
    static_assert( (std::is_same_v <double, Ts> && ...) , 
        "All the arguments of the template should be doubles");
    public: 
      using _func = std::function<double(Ts...)>;

      void set_diff_tolerance(double eps);


      BFunction() = default;
      BFunction(_func basisFunction );
      BFunction(const BFunction& other);

      void set(_func);
      const BFunction& operator = (const BFunction& that);
      double operator () (Ts...) const;
      double operator () (const Point<Ts...>& p) const;

      constexpr int dimensionality() const;
       _func derWithRespectTo(int i);

    private: 

      double _eps = 1e-6;
      _func _basisFunction;

  };


  // Member Definition 
  template<typename ...Ts>
  void BFunction<Ts...>::set_diff_tolerance(double eps)
  {
    _eps = eps;
  }

  template<typename ...Ts>
  BFunction<Ts...>::BFunction(_func basisFunction):
    _basisFunction(basisFunction)
  {}

  template<typename ...Ts> 
  BFunction<Ts...>::BFunction(const BFunction<Ts...>& other):
  _basisFunction(other._basisFunction)
  {}

  template<typename ...Ts>
  double BFunction<Ts...>::operator()(Ts... args) const
  { 
    return _basisFunction(args...);
  }

  template<typename... Ts>
  double BFunction<Ts...>::operator()(const Point<Ts...>& p) const
  {
    const double* pp = p.get();


    if      constexpr (sizeof...(Ts) == 1) return _basisFunction(pp[0]);
    else if constexpr (sizeof...(Ts) == 2) return _basisFunction(pp[0], pp[1]);
    else if constexpr (sizeof...(Ts) == 3) return _basisFunction(pp[0], pp[1], pp[2]);
    else  throw NotImplementedError();

  }

  template<typename ...Ts>
  void BFunction<Ts...>::set(_func bfunct)
  {
    _basisFunction = bfunct;
  }

  template<typename ...Ts> 
    constexpr int BFunction<Ts...>::dimensionality() const
    {
      return sizeof...(Ts);
    }

  template<typename ...Ts>
    std::function<double(Ts...)>  
    BFunction<Ts...>::derWithRespectTo(int i)
    {

      throw FEM::NotGerericImplementation("The function derWithRespectTo is not implemented in generic type.");
    }
}

#endif 
