#ifndef _FEM_BFUNCTIONCOLLECTION_INCLUDED_ 
#define _FEM_BFUNCTIONCOLLECTION_INCLUDED_ 

#include "BasisFunctions/BasisFunction.h"
#include <vector>
#include <initializer_list>


namespace FEM 
{
  template<typename... Ts> 
    class BFunctionCollection;

  using BFunctionCollection1D = BFunctionCollection<double>;
  using BFunctionCollection2D = BFunctionCollection<double,double>;
  using BFunctionCollection3D = BFunctionCollection<double,double, double>;

template <typename... Ts>
class BFunctionCollection  : private std::vector<BFunction<Ts...>>
{
  public: 

    BFunctionCollection();
    BFunctionCollection(std::initializer_list<BFunction<Ts...>> ll);
    BFunctionCollection( const            BFunctionCollection&  ) = delete;
    BFunctionCollection(                  BFunctionCollection&& ) = delete;
    BFunctionCollection& operator= (const BFunctionCollection&  ) = delete;
    BFunctionCollection& operator= (      BFunctionCollection&& ) = delete;

    int size() const; 
    BFunction<Ts...>& phi(int i);

  private:


  
};


template<typename... Ts> 
BFunctionCollection<Ts...>::BFunctionCollection(std::initializer_list<BFunction<Ts...>> ll)
{
  for (const BFunction<Ts...>& fn : ll)
    this->push_back(fn);
 
}



template<typename... Ts> 
int BFunctionCollection<Ts...>::size() const
{
 return std::vector<BFunction<Ts...>>::size(); 
}

template<typename... Ts> 
BFunction<Ts...>&  BFunctionCollection<Ts...>::phi(int i)
{
  return this->at(i); 
}




}

#endif
