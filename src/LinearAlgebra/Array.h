#ifndef _FEM_ARRAY_INCLUDED_
#define _FEM_ARRAY_INCLUDED_

#include <iostream> 
#include <initializer_list>
#include <numeric>
#include <cmath>
#include "exceptions.h"



namespace FEM 
{





  class Array 
  {
    public: 
      Array() = default;
      Array(int size, double init = 0.0);
      Array(std::initializer_list<double> il);
      Array(const Array& other);
      Array( Array&& other);
      ~Array();

      Array& operator = (const Array& that);
      Array& operator = ( Array&& that);

      int size() const;
      double& get(int i) noexcept;
      double  get(int i) const noexcept;

      double* begin()  { return  m_values;}
      double* end()    { return (m_values + m_size);}



      Array  operator+ (const Array& other);
      Array& operator+=(const Array& other);
      Array  operator- (const Array& other);
      Array& operator-=(const Array& other);

      double&  operator() (int i);
      double   at(int i) const;

      double L2norm();
      

    private: 
      int m_size = 0;
      double* m_values = nullptr;
  };


}


#endif
