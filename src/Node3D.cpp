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

  std::ostream& operator << (std::ostream& out, const Node3D& obj){


    out << "Node3D("<< obj.getLabel() << ","
                    << obj.getX()     << "," 
                    << obj.getY()     << "," 
                    << obj.getZ()     <<")\n";
    return out;
  }


  bool Node3D::operator == (const Node3D& other)
  {

    return m_label      == other.getLabel() && 
           this->getX() == other.getX()     && 
           this->getY() == other.getY()     && 
           this->getZ() == other.getZ();
  }


  bool Node3D::operator != (const Node3D& other)
  {
    return !this->operator==(other);
  }


}

