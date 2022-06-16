#include "Brick.h"


namespace FEM
{

  Brick::Brick(const Brick& other) : 
    m_label(other.m_label),
    nnodes (other.nnodes),
    m_nodes(other.m_nodes)
  {}

  // shallow copy
  Brick& Brick::operator=(const Brick &that)
  {
    if (this == &that)
      return *this;

    m_label = that.m_label;
    nnodes  = that.nnodes;
    m_nodes = that.m_nodes;
    
    return *this;
  }


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
