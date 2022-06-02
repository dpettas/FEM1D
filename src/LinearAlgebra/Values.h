#ifndef _FEM_LINEAR_ALGEBRA_VALUES_INCLUDED_
#define _FEM_LINEAR_ALGEBRA_VALUES_INCLUDED_ 

#include <vector>
#include "exceptions.h"

namespace FEM 
{
  class Array;

  class Values : public std::vector<double*>
  {
  public: 
    Values() = default;
    Values(const Array& init) = delete;

    Values operator= (const Array& arr);
  };
}

#endif
