#include "GaussPoint1D.h"


namespace FEM 
{
  GaussPoint1D::GaussPoint1D(double position, double weight):
    m_position(position), 
    m_weight(weight)
  {
  }



  std::pair<double,double> GaussPoint1D::get() const
  {
    return std::pair<double,double> (m_position,m_weight);
  }


}
