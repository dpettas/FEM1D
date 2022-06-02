#include "Values.h"
#include "Array.h"
#include "DenseMatrix.h"

namespace FEM 
{
  ArrayValues& ArrayValues::operator = (const Array& arr)
  {
    if (arr.size() != (int) size() )
      throw NotEqualBalancedArrays("Values::operator =(const Array& arr)");

    for (int i = 0; i < (int) size(); ++i)
      *at(i) = arr.get(i);

    return *this;
  }


  // Values& Values::operator=(const DenseMatrix& mat)
  // {
  //   if (mat.getSize() != (int) size() )
  //     throw NotEqualBalancedArrays("Values::operator =(const DenseMatrix&)");
  //
  //   for (int i = 0; i < (int) size(); ++i)
  //     *at(i) = mat.get(i);
  //
  //
  //   return *this;
  // }



}
