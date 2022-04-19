#include "Point1D.h"

namespace FEM
{

  Point1D::Point1D()
  {
    num  = 1;
    xx   = 0.0;
  };

  Point1D::Point1D(double x_)
  {
    num = 1;
    xx = x_;
  }

  Point1D::Point1D(const Point1D& rhs)
  {

  }



  
  const int& Point1D::numberOfDimensions() const 
  {
    return num;
  }

  const double* Point1D::getCoordinates() const
  {
    return &xx;
  }

  const double Point1D::distance(const Point& other) const
  {
    double c1[3]; 
    double c2[3];

    for(int i = 0; i < this ->numberOfDimensions(); ++i) c1[i] = 0.0;
    for(int i = 0; i < other. numberOfDimensions(); ++i) c2[i] = 0.0;
    
    for(int i = 0; i < this ->numberOfDimensions(); ++i) c1[i] = this->getCoordinates()[i];
    for(int i = 0; i < other. numberOfDimensions(); ++i) c2[i] = other.getCoordinates()[i];

    return std::sqrt(std::pow(c1[0]-c2[0],2) + std::pow(c1[1]-c2[1],2) +  std::pow(c1[2]-c2[2],2));

  }

}


