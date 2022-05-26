#include "Array.h"

namespace FEM 
{
  Array::Array(int size, double init) : 
    m_size(size)
  {
    m_values = new double [m_size];

    for (int i = 0; i < m_size; ++i)
      m_values[i] = 0.0;
  
  }

  Array::Array(const Array& other)
  {
    m_size = other.m_size;

    m_values = new double [m_size];

    for (int i = 0; i < m_size; ++i)
      m_values = other.m_values;
  }





  Array::~Array()
  {
    delete [] m_values;
    m_size = 0;
  }


}
