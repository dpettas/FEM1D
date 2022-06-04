#include "BasisFunctions/BasisFunction1D.h"

namespace FEM 
{

void BasisFunction1D::set_diff_tolerance(double eps)
{
  _eps = eps;
}


BasisFunction1D::BasisFunction1D(_func _basisFunction) : 
  m_basisFunction(_basisFunction)
{}

BasisFunction1D::BasisFunction1D(const BasisFunction1D& other) :
  m_basisFunction(other.m_basisFunction)
{}

BasisFunction1D& BasisFunction1D::operator=(const BasisFunction1D &that)
{
  if (this == &that)
    return *this;

  m_basisFunction = that.m_basisFunction;

  return *this;
}

int BasisFunction1D::dimensionality() const 
{
  return 1;
}

double BasisFunction1D::operator() (double x1)
{
  return m_basisFunction(x1);
}


BasisFunction1D::_func BasisFunction1D::dx1()
{
  return [this] (double x1) { return (m_basisFunction(x1 + _eps) - m_basisFunction(x1)) / _eps; };
};

}

