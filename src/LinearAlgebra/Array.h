#include <iostream> 
#include <initializer_list>

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
      double& get(int i);
      double  get(int i) const;
      

    private: 
      int m_size = 0;
      double* m_values = nullptr;
  };


}
