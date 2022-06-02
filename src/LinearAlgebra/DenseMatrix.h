#ifndef _FEM_DENSEMATRIX_INCLUDED_
#define _FEM_DENSEMATRIX_INCLUDED_ 

#include <iostream>
#include <iomanip>
#include <utility>
#include <initializer_list>
#include <unordered_set>
#include "LinearAlgebra/Indices.h"
#include "LinearAlgebra/DenseMatrixValues.h"
#include "LinearAlgebra/exceptions.h"




namespace FEM 
{
  class DenseMatrix
  {
    public:



      DenseMatrix() = default;
      ~DenseMatrix();
      DenseMatrix(int n, int m, double val = 0.0);
      DenseMatrix(std::initializer_list<std::initializer_list<double>> ll);
      DenseMatrix(const DenseMatrix& other);

      std::pair<int,int> getDimensions() const;


      int size()     const;
      int getSize()  const;
      int getNrows() const;
      int getNcols() const;

      double& get(int i);
      const double& get(int i) const;

      double&       value(int i, int j);
      const double& value(int i, int j) const;

      double& diagonal(int i);
      const double& diagonal(int i) const;

      double* begin(); 
      const double* begin() const;
      double*   end(); 
      const double* end() const;


      double&       operator () (int i, int j);
      const double& operator () (int i, int j) const;

      DenseMatrixValues operator() (const Indices& idx_x, const Indices& idx_y);


    
    private: 
      int data_index(int i, int j) const;

      int m_rows = 0; 
      int m_cols = 0; 
      int m_size = 0;
      double* m_val = nullptr;
  };  


  std::ostream& operator << (std::ostream& out, const FEM::DenseMatrix& mat);

}




#endif
