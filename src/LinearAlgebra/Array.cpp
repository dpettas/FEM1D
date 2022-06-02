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
      m_values[i] = other.m_values[i];
  }



  int Array::size() const 
  {
    return m_size;
  }

  double& Array::get(int i) noexcept
  {
    return m_values[i];
  }

  double Array::get(int i) const noexcept
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


    return out;
  }

  Array& Array::operator+=(const Array& other)
  {

    if (this->size() != other.size() )
      throw NotEqualSizedArrays("Array::opereator +=");


    for (int i = 0; i < m_size; ++i)
      m_values[i] += other.m_values[i]; 


    return *this;
  }



  Array Array::operator- (const Array& other)
  {
    Array out;

    if (this->size() != other.size() )
      throw NotEqualSizedArrays("Array::opereator -");


    out = *this;
    for (int i = 0; i < m_size; ++i)
      out.m_values[i] -= other.m_values[i]; 


    return out;
  }

  Array& Array::operator-=(const Array& other)
  {

    if (this->size() != other.size() )
      throw NotEqualSizedArrays("Array::opereator -=");


    for (int i = 0; i < m_size; ++i)
      m_values[i] += other.m_values[i]; 


    return *this;
  }


  double& Array::operator() (int i)
  {
    if (i >= m_size || i < 0)
      throw OutOfBoundsIndex("Array::operator ()", i);

    return m_values[i];
  }


  Array::Values Array::operator () (const Array::Indices& idx)
  {
    Values out;
    for (int i = 0; i < idx.size(); ++i)
      out.add(m_values[idx.get(i)]);

    return out;
  }


  double Array::at(int i) const 
  {
    if (i >= m_size || i < 0)
      throw OutOfBoundsIndex("Array::at ()", i);

    return m_values[i];
  }



  double Array::L2norm()
  {
    std::for_each( this->begin(), 
                   this->end(), 
                   [this] (int i)
                   { return m_values[i]*m_values[i];});


    double sum_square = std::accumulate(this->begin(), this->end(), 0);

    return std::sqrt(sum_square);
  }



}
