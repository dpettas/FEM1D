#include "Array.h"

namespace FEM 
{
  Array::Array(int size, double init) : 
    m_size(size)
  {
    std::cout << "init" << std::endl;
    m_values = new double [m_size];

    for (int i = 0; i < m_size; ++i)
      m_values[i] = 0.0;
  
  }

  Array::Array(std::initializer_list<double> il)
  {
    m_size = il.size();

    m_values = new double [m_size];

    int idx = 0;
    for(std::initializer_list<double>::iterator it = il.begin(); 
        it != il.end(); 
        ++it) 
    {
      m_values[idx] = *it;
      ++idx; 
    }
    
  }


  int Array::size() const 
  {
    return m_size;
  }

  double& Array::get(int i)
  {
    return m_values[i];
  }

  double Array::get(int i) const 
  {
    return m_values[i];
  }




  Array::Array(const Array& other)
  {
    std::cout << "copy" << std::endl;
    m_size = other.m_size;

    m_values = new double [m_size];

    for (int i = 0; i < m_size; ++i)
      m_values = other.m_values;
  }



  Array::Array(Array&& other)
  {
    std::cout << "move" << std::endl;
    delete [] m_values;
    m_size   = other.m_size;
    m_values = other.m_values;

    other.m_values = nullptr;
  }

  Array::~Array()
  {
    delete [] m_values;
    m_size = 0;
  }


}
