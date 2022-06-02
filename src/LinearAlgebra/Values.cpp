#include "Values.h"
#include "Array.h"

namespace FEM 
{
  Values Values::operator = (const Array& arr)
  {
    if (arr.size() != (int) size() )
      throw NotEqualBalancedArrays("Array::Values::operator =");

    for (int i = 0; i < (int) size(); ++i)
      *at(i) = arr.get(i);

    return *this;
  }



}
