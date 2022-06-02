#ifndef _FEM_LINEAR_ALGEBRA_DENSEMATRIXVALUES_INCLUDED_
#define _FEM_LINEAR_ALGEBRA_DENSEMATRIXVALUES_INCLUDED_ 


#include <vector>
#include "exceptions.h"

namespace FEM 
{
  class Array;
  class DenseMatrix;

  class DenseMatrixValues : public std::vector<double*>
  {
  public: 
    DenseMatrixValues() = default;
    DenseMatrixValues(const Array& init) = delete;

    DenseMatrixValues& operator= (const DenseMatrix& mat);
  };
}




#endif
