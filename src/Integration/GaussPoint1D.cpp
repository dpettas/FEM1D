#include "GaussPoint1D.h"


namespace FEM 
{
  GaussPoint1D::GaussPoint1D(double position, double weight)
  {
    m_position = new double (position);
    m_weight   = weight;
  }

  GaussPoint1D::GaussPoint1D(const GaussPoint1D& other)
  {
    m_position = new double;
    m_weight   = other.m_weight;

    *m_position = *other.m_position;
  }
  
  GaussPoint1D::GaussPoint1D( GaussPoint1D&& other)
  {
    delete m_position;

    m_position       = other.m_position;
    m_weight         = other.m_weight;
    other.m_position = nullptr;
    other.m_weight   = 0;
  }

  GaussPoint1D& GaussPoint1D::operator=(const GaussPoint1D &that)
  {
    if (this == &that)
      return *this; 

    delete m_position;

    m_position  = new double;
    m_weight    = that.m_weight;
    *m_position = *that.m_position;
    

    return *this;
  }

  GaussPoint1D& GaussPoint1D::operator=(GaussPoint1D&& that)
  {
    if (this == &that)
      return *this;

    m_position       = that.m_position;
    m_weight         = that.m_weight;
    that.m_position  = nullptr;
    that.m_weight    = 0;


    return *this;
  }



}
