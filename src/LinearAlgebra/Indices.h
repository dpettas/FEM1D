#ifndef _FEM_LINEAR_ALGEBRA_INDICES_INCLUDED_
#define _FEM_LINEAR_ALGEBRA_INDICES_INCLUDED_ 

#include <initializer_list>
#include <vector>
#include "exceptions.h"




namespace FEM 
{
class Array;
class Indices 
{
public: 
  Indices(std::initializer_list<int> il);

  int size()       const;
  int get(int idx) const;
  int* begin()     const;
  int* end()       const;

  ~Indices();

private: 
  int  m_size = 0; 
  int* m_val  = nullptr;
};

class Values 
{
public: 
  Values() = default;
  Values(const Array& init) = delete;

  Values operator = (const Array& arr);

  void add(double& val) {return m_values.push_back(&val);}
  double* get(int i) const {return m_values.at(i);}
private:
  std::vector<double*> m_values;


};

}
#endif
