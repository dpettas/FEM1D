#include "DenseMatrixValues.h"
#include "DenseMatrix.h"


namespace FEM 
{

  DenseMatrixValues& DenseMatrixValues::operator=(const DenseMatrix& mat)
  {
    if (mat.getSize() != (int) size() )
      throw NotEqualBalancedArrays("Values::operator =(const DenseMatrix&)");

    for (int i = 0; i < (int) size(); ++i)
      *at(i) = mat.get(i);


    return *this;
  }




}
