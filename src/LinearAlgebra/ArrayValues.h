#ifndef _FEM_LINEAR_ALGEBRA_VALUES_INCLUDED_
#define _FEM_LINEAR_ALGEBRA_VALUES_INCLUDED_ 

#include <vector>
#include "exceptions.h"

namespace FEM 
{
  class Array;
  class DenseMatrix;

  class ArrayValues : public std::vector<double*>
  {
  public: 
    ArrayValues() = default;
    ArrayValues(const Array& init) = delete;

    ArrayValues& operator= (const Array& arr);
    // Values& operator= (const DenseMatrix& mat);
  };
}

#endif
