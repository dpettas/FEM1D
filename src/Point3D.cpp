#include "Point3D.h"

namespace FEM{


Point3D::Point3D(double x, double y, double z): m_x(x), m_y(y), m_z(z)
{

}

void Point3D::setX(double x){ m_x = x;}
void Point3D::setY(double y){ m_y = y;}
void Point3D::setZ(double z){ m_z = z;}

double& Point3D::getX(){ return m_x;}
double& Point3D::getY(){ return m_y;}
double& Point3D::getZ(){ return m_z;}

const double& Point3D::getX() const { return m_x;}
const double& Point3D::getY() const { return m_y;}
const double& Point3D::getZ() const { return m_z;}


bool Point3D::operator==(const Point3D& other){
  return std::abs(m_x - other.getX()) <= 1.e-8 &&
         std::abs(m_y - other.getY()) <= 1.e-8 &&
         std::abs(m_z - other.getZ()) <= 1.e-8;
}

bool Point3D::operator!=(const Point3D& other){
  return !this->operator==(other);
}

double Point3D::distanceFrom(const Point3D& other)
{
 if (*this == other) return 0.0;

 double out; 
 out = 0.0;
 out+= std::pow( m_x - other.getX(), 2);
 out+= std::pow( m_y - other.getY(), 2);
 out+= std::pow( m_z - other.getZ(), 2);
 out = std::sqrt(out);
 return out;
}




std::ostream& operator << (std::ostream& out, const Point3D& obj)
{
  out << "Point3D("<<obj.getX() << "," << obj.getY() << "," << obj.getZ() << ")";

  return out;
}

}
