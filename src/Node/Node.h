#ifndef _FEM_NODE_INCLUDED_
#define _FEM_NODE_INCLUDED_ 

#include "Point/Point.h"
#include <iostream>


namespace FEM 
{
  
  template<typename... Ts>
  class Node : public Point<Ts...>
  {
    public: 
      Node();
      Node(int label, Ts... coors);
      Node(int label, const Point<Ts...>& point);
      Node( const Node&  other);
      Node(       Node&& other);

      Node& operator = (const Node&  that); 
      Node& operator = (      Node&& that);

      int getLabel() const;
    private:

      int _label;
    
  };


template<typename... Ts>
  std::ostream& operator << (std::ostream& out, const Node<Ts...>& obj)
  {
    Point<Ts...> pout = obj;


    out << "("<< obj.getLabel() << ", " << pout << ")"<< std::endl;

    return out; 
  }

template <typename... Ts>
  int Node<Ts...>::getLabel() const
  {
    return _label; 
  }

template <typename... Ts> 
  Node<Ts...>::Node()
  {
    _label = 0;
  }
  


}





#endif
