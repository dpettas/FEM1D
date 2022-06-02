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
  ~Indices();

  int size()       const;
  int get(int idx) const;
  int* begin()     const;
  int* end()       const;


private: 
  int  m_size = 0; 
  int* m_val  = nullptr;
};


}
#endif
