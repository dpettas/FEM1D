#include "solver_lapack.h"

namespace FEM::ALGEBRA 
{
  SolverLapack::~SolverLapack()
  {
    if (alloc)
      delete [] ipiv;
  }


  void SolverLapack::factorize(DenseMatrix& a)
  {
    factorize(a.getNrows(), a.getNcols(), a.begin());
  }


  void SolverLapack::solve(const DenseMatrix& a, Array& b)
  {
    solve(b.size(), a.begin(), b.begin());
  }


  void SolverLapack::factorize(int m, int n, double* a)
  {
    lda = m;
    ipiv  = new int [(m<n) ? m : n ];
    alloc = true; 

    LAPACK_dgetrf(&m,&n,a,&lda, ipiv, &info);

    if (info == 0) return;

    if (info <  0)
      throw LapackArgumentIllegalValue("SolverLapack::factorize", info);

    if (info >  0)
      throw LapackZeroDiagonalValue("SolverLapack::factorize", info);
  }

  void SolverLapack::solve(int n, const double* a, double* b, int nrhs)
  {
    trans = 'N';
    lda   = n;
    ldb   = n;

    dgetrs_(&trans,&n,&nrhs,a,&lda,ipiv,b,&ldb,&info);
    if (info == 0) return;

    if (info <  0)
      throw LapackArgumentIllegalValue("SolverLapack::solve", info);

    return;
  }



}
