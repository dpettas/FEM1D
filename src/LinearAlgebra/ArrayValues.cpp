#include "ArrayValues.h"
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

  ArrayValues& ArrayValues::operator += (const Array& arr)
  {
    if (arr.size() != (int) size() )
      throw NotEqualBalancedArrays("Values::operator =(const Array& arr)");

    for (int i = 0; i < (int) size(); ++i)
      *at(i) += arr.get(i);

    return *this;
  }

  ArrayValues& ArrayValues::operator -= (const Array& arr)
  {
    if (arr.size() != (int) size() )
      throw NotEqualBalancedArrays("Values::operator =(const Array& arr)");

    for (int i = 0; i < (int) size(); ++i)
      *at(i) -= arr.get(i);

    return *this;
  }





}
