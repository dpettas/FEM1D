#include "Brick.h"


namespace FEM 
{
  int Brick::getNumberOfNodes() const 
  {
    return nnodes;
  }

  void Brick::addNode(const Node3D& node)
  {
    m_nodes.push_back(&node);
  }


}
