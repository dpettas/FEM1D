#include "Brick.h"
#include <iostream>


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


  Point3D Brick::centroid() const
  {
    double x1= 0.0;
    double x2= 0.0;
    double x3= 0.0;

    for (int i = 0; i < getNumberOfNodes(); ++i )
    {
      const Node3D& n = this->getNode(i);
      x1 += n.component(0);
      x2 += n.component(1);
      x3 += n.component(3);
    }
    x1 /= this->getNumberOfNodes();
    x2 /= this->getNumberOfNodes();
    x3 /= this->getNumberOfNodes();

    return Point3D(x1,x2,x3);
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
