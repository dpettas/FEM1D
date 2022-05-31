#include "Matrices.h"


namespace FEM 
{
  DenseMatrix square(int n, double m_val)
  {
    DenseMatrix out(n,n,m_val);
    return out;
  }

}
