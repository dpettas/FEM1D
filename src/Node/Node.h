#ifndef _FEM_NODE_INCLUDED_
#define _FEM_NODE_INCLUDED_ 

#include "Point/Point.h"
#include <iostream>


namespace FEM 
{
  template<typename... Ts> 
    class Node; 

  using Node1D = Node<double>;
  using Node2D = Node<double, double>;
  using Node3D = Node<double, double, double>;

 
  template<typename... Ts>
  class Node : public Point<Ts...>
  {
    public: 
      Node();
      Node(int label, Ts... coors);
      Node(int label, const Point<Ts...>& point);
      Node( const Node&  other);
      Node(       Node&& other);

      void setLabel(int label);


      int  getLabel() const;

      Node& operator = (const Node&  that); 
      Node& operator = (      Node&& that);
      bool  operator ==(const Node&  other) const;

    private:

      int _label = -1;
    
  };

 template <typename... Ts> 
   Node<Ts...>::Node(int label, const Point<Ts...>& point)
   : Point<Ts...>::Point(point), _label(label)
   {}

 template <typename... Ts> 
   Node<Ts...>::Node(int label, Ts... coords)
   : Point<Ts...>::Point(coords...), _label(label)
   {}


template <typename... Ts>
  int Node<Ts...>::getLabel() const
  {
    return _label; 
  }

template <typename... Ts> 
  Node<Ts...>::Node() 
  : Point<Ts...>::Point()
  {
    _label = 0;
  }

 template <typename... Ts> 
  void Node<Ts...>::setLabel(int label)
  {
    _label = label;
  }


template <typename... Ts> 
   Node<Ts...>::Node(const Node& other)
   : Point<Ts...>::Point(other)
   {
     _label = other._label;
   }

template <typename... Ts> 
   Node<Ts...>::Node( Node&& other)
   : Point<Ts...>::Point(other)
   {
     _label = other._label;
     other._label = -1;
   }


  template<typename... Ts> 
    bool Node<Ts...>::operator==(const Node& other) const
    {
      return (_label == other._label) && Point<Ts...>::operator==(other);

    }

}





#endif
