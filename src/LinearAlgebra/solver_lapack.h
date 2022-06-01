#ifndef _LINEAR_ALGEBRA_SOLVER_LAPACK_
#define _LINEAR_ALGEBRA_SOLVER_LAPACK_ 

#include "Array.h"
#include "DenseMatrix.h"
#include "exceptions.h"
#include "lapacke.h"


namespace FEM::ALGEBRA
{


class SolverLapack 
{
  public: 

  SolverLapack() = default;
  ~SolverLapack();

  void factorize(int m, int n, double* a);
  void factorize(DenseMatrix& a);

  void solve(int n, const double* a, double* b, int nrhs = 1);
  void solve(const DenseMatrix& a, Array& b);

  private:

    char    trans;
    int     info ;
    int     lda  ;
    int     ldb  ;
    int     n    ;
    int     nrhs ;
    bool    alloc= false;
    int*    ipiv = nullptr;
};





}





#endif
