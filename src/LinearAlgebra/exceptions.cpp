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


  OutOfBoundsIndex::OutOfBoundsIndex(const std::string& whichFunction, int i)
  {
    std::stringstream out; 

    out << whichFunction; 
    out << " : ";
    out << " The index ";
    out << i;
    out << " is out of bounds";

    msg = out.str();
  }

  const char * OutOfBoundsIndex::what() const noexcept
  {
    return msg.c_str();
  }

}
