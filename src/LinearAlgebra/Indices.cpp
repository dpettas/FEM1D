#include "Indices.h"
#include "Array.h"

namespace FEM 
{


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
