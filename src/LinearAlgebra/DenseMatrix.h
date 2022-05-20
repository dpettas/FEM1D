#ifndef _FEM_DENSEMATRIX_INCLUDED_
#define _FEM_DENSEMATRIX_INCLUDED_ 

#include <iostream>
#include <iomanip>
#include <utility>

namespace FEM 
{
  class DenseMatrix
  {
    public:
      DenseMatrix() = default;
      ~DenseMatrix();
      DenseMatrix(int n, int m, double val = 0.0);
      DenseMatrix(const DenseMatrix& other);

      std::pair<int,int> getDimensions() const;


      int getSize() const;
      double&       value(int i, int j);
      const double& value(int i, int j) const;

      double* begin(); 
      double*   end(); 


    
    private: 
      int data_index(int i, int j) const;



      int m_rows = 0; 
      int m_cols = 0; 
      int m_size = 0;
      double* m_val = nullptr;
  };  std::ostream& operator << (std::ostream& out, const FEM::DenseMatrix& mat);

}
#endif