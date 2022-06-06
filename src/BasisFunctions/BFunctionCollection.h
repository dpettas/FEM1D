#ifndef _FEM_BFUNCTIONCOLLECTION_INCLUDED_ 
#define _FEM_BFUNCTIONCOLLECTION_INCLUDED_ 

#include "BasisFunctions/BasisFunction.h"
#include <vector>
#include <initializer_list>


namespace FEM 
{

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
    const BFunction<Ts...>& phi(int i) const;

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
 return std::vector<Ts...>::size(); 
}

template<typename... Ts> 
const BFunction<Ts...>&  BFunctionCollection<Ts...>::phi(int i) const 
{
  return this->at(i); 
}




}

#endif
