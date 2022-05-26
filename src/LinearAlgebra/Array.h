#include <iostream> 
#include <initializer_list>

namespace FEM 
{

  class Array 
  {
    public: 
      Array() = default;
      Array(int size, double init = 0.0);
      Array(std::initializer_list<double>);
      Array(const Array& other);
      Array( Array&& other);
      ~Array();

      Array& operator = (const Array& that);
      Array& operator = ( Array&& that);
      

    private: 
      int m_size = 0;
      double* m_values = nullptr;
  };


}
