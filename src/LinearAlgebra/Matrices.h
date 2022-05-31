#ifndef _FEM_LINEAR_ALGEBRA_MATRICES_INCLUDED_
#define _FEM_LINEAR_ALGEBRA_MATRICES_INCLUDED_

#include "DenseMatrix.h"

namespace FEM 
{

 // If I use template, the type cannot be deduced
  DenseMatrix Square  (int i, double val = 0.0);
  DenseMatrix Diagonal(int i, double val = 0.0);
  DenseMatrix Identity(int i);
  DenseMatrix Zeros   (int i, int j);
  DenseMatrix Ones    (int i, int j);



}


#endif
