#include "Matrices.h"


namespace FEM 
{

DenseMatrix Square(int i, double val)
{
  return DenseMatrix(i,i, val); // elision
}

DenseMatrix Diagonal(int i, double val)
{
  DenseMatrix out(i,i);
  for (int ii = 0; ii < out.getNrows(); ++ii )
    out(ii,ii) = val;

  return out;
}

DenseMatrix Identity(int i)
{
  return Diagonal(i,1.0);
}

DenseMatrix Zeros(int i, int j)
{
  return DenseMatrix(i,j,0.0);
}

DenseMatrix Ones(int i, int j)
{
  return DenseMatrix(i,j,1.0);
}



}
