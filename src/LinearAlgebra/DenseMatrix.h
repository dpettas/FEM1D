#ifndef _FEM_DENSEMATRIX_INCLUDED_
#define _FEM_DENSEMATRIX_INCLUDED_ 

class DesnseMatrix
{
  public:
    DesnseMatrix() = default;
    DesnseMatrix(const DesnseMatrix& other);
    DesnseMatrix(int n, int m, double val = 0.0);

  private: 
    int m_n; 
    int m_m; 
    double* val;
};

#endif
