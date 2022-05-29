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
    for(double val : il) 
    {
      m_values[idx] = val;
      ++idx; 
    }
    
  }


  Array::Array(const Array& other)
  {
    m_size = other.m_size;

    m_values = new double [m_size];

    for (int i = 0; i < m_size; ++i)
      m_values = other.m_values;
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


  Array& Array::operator=(const Array& that)
  {
    if (this == &that)
      return *this;

    // check if m_values is nullptr
    if (!m_values)
    {
      m_size = that.m_size;
      m_values = new double [m_size];

      for (int i = 0; i < m_size; ++i)
        m_values[i] = that.m_values[i];

      return *this;
    }

    // arrays have the same sizes
    if (m_size == that.m_size)
    {
      for (int i = 0; i < m_size; ++i)
        m_values[i] = that.m_values[i];

      return *this;
    }
    else 
    {
      delete [] m_values;
      m_size = that.m_size;
      m_values = new double [m_size];

      for (int i = 0; i < m_size; ++i)
        m_values[i] = that.m_values[i];

      return *this;

    }

    throw "NotImplemented\n";
  }







  Array& Array::operator = (Array&& that)
  {
    if (this == &that)
      return *this;

    m_size        = that.m_size;
    m_values      = that.m_values;
    that.m_values = nullptr;
    that.m_size   = 0;


    return *this;
  }




  Array::Array(Array&& other)
  {
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


  
  Array Array::operator+ (const Array& other)
  {
    Array out;

    if (this->size() != other.size() )
      throw NotEqualSizedArrays("Array::opereator +");


    out = *this;
    for (int i = 0; i < m_size; ++i)
      out.m_values[i] += other.m_values[i]; 


    return std::move(out);
  }






}
