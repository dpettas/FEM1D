#include "LinearAlgebra/exceptions.h"

namespace FEM 
{


  NotEqualSizedArrays::NotEqualSizedArrays(const std::string& whichFunction)
  {
    msg = whichFunction + " : The Arrays do not have the same size";
  }

  const char * NotEqualSizedArrays::what() const noexcept
  {
    return msg.c_str();
  }

}
