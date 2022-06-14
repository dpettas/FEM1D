#ifndef _FEM_GPOINTCOLLECTION_INCLUDED_ 
#define _FEM_GPOINTCOLLECTION_INCLUDED_ 

#include "Integration/GPoint.h"

#include <initializer_list>
#include <iostream>
#include <vector>

namespace FEM 
{

 //  template <typename... Ts>
 //  class GPointCollection : private std::vector<GPoint<Ts...>>
 //  {
 //    public:
 //
 //
 //      GPointCollection() = default;
 //
 //      GPointCollection(std::initializer_list<GPoint<Ts...>> l );
 //
 //      const GPoint<Ts...>& get(int i) const;
 //      int size() const;
 // 
 //  };
 //
 //
 //
 //  template<typename... Ts> 
 //    GPointCollection<Ts...>::GPointCollection(std::initializer_list<GPoint<Ts...>> l)
 //    {
 //      for (const GPoint<Ts...>& pt : l)
 //        this->push_back(pt);  
 //    }
 //
 //  template<typename... Ts> 
 //    const GPoint<Ts...>& GPointCollection<Ts...>::get(int i) const
 //    {
 //      return this->at(i); 
 //    }
 //
 //
 //  template<typename... Ts> 
 //    int GPointCollection<Ts...>::size() const 
 //    {
 //      return std::vector<GPoint<Ts...>>::size();
 //    }
 //

}
#endif
