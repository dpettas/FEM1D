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

  const Node3D& Brick::getNode(int id) const
  {
    return *m_nodes.at(id);
  }


  const std::vector<int> Brick::getNodeLabels() const 
  {
    std::vector<int> out; 
    for(const Node3D* node: m_nodes)
    {
      out.push_back(node->getLabel());
    }
    return out;
  }

}
