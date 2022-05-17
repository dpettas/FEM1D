#include "Node3D.h"

namespace FEM
{

  Node3D::Node3D(int label, double x, double y, double z) : Point3D(x,y,z), m_label(label) 
  {
  }

  Node3D::Node3D(int label, const Point3D& p){

    m_label = label;
    this->getX() = p.getX();
    this->getY() = p.getY();
    this->getZ() = p.getZ();
  }


  void Node3D::setLabel(int label)
  {
    m_label = label;
  }

  int& Node3D::getLabel()
  {
    return m_label;
  }


  const int& Node3D::getLabel() const
  {
    return m_label;
  }

}

