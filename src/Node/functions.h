#ifndef _FEM_POINT_FUNCTIONS_INCLUDED_
#define _FEM_POINT_FUNCTIONS_INCLUDED_ 


#include "Node/Node.h"
#include "Point/operators.h"

namespace FEM 
{

  // Creates New Node 
  template<typename... Ts>
    Node<Ts...> makeNode(int label, Ts... coords)
    {
      Node<Ts...> out; 
      out.setLabel(label);
      int i = 0;
      ( (out.component(i++) = coords), ...);
      return out;
    }
    

  template<typename... Ts>
    std::ostream& operator << (std::ostream& out, const Node<Ts...>& obj)
    {
      out << "("<< obj.getLabel() << ", " 
          << static_cast<Point<Ts...> >(obj) << ")";
      return out; 
    }



}




#endif
