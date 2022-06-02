#include "Indices.h"
#include "Array.h"

namespace FEM 
{
  Values Values::operator = (const Array& arr)
  {
    if (arr.size() != (int) m_values.size() )
      throw NotEqualBalancedArrays("Array::Values::operator =");

    for (int i = 0; i < (int) m_values.size(); ++i)
    {
      *m_values[i] = arr.get(i);
    }

    return *this;
  }


  Indices::~Indices() 
  {
    delete [] m_val;
  }


  Indices::Indices(std::initializer_list<int> il) 
  {
    m_size = il.size();
    m_val  = new int [m_size];

    int i = 0;
    for (int val : il)
    {
      m_val[i] = val;
      ++i;
    }
  }


  int Indices::size() const 
  {
    return m_size;
  }

  int Indices::get(int idx) const 
  {
    return m_val[idx];
  }

  int* Indices::begin() const 
  {
    return m_val;
  }


  int* Indices::end() const 
  {
    return m_val + m_size;
  }


}
