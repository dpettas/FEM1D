#include "LinearAlgebra/DenseMatrix.h"
#include "LinearAlgebra/exceptions.h"

namespace FEM 
{




  DenseMatrix::DenseMatrix(int n, int m, double val)
  {
    m_rows    = n; 
    m_cols    = m;
    m_size = m_rows * m_cols;
    m_val  = new double [m_size];

    for(int i = 0; i < m_size; ++i)
      m_val[i] = val;
  }

  DenseMatrix::DenseMatrix(const DenseMatrix& other)
  {
    m_rows = other.m_rows;
    m_cols = other.m_cols; 
    m_size = other.m_size;
    m_val  = new double [m_size];

    for(int i = 0; i < m_size; ++i)
      m_val[i] = other.m_val[i];
  }

  std::pair<int,int> DenseMatrix::getDimensions() const
  {
    return std::make_pair(m_rows, m_cols);
  }

  int DenseMatrix::data_index(int i, int j) const
  {
    return i * m_cols + j;
  }

  double& DenseMatrix::value(int i, int j)
  {
    return m_val[this->data_index(i,j)];
  }

  const double& DenseMatrix::value(int i, int j) const
  {
    return m_val[this->data_index(i,j)];
  }

  double* DenseMatrix::begin()
  {
    return m_val;
  }

  const double* DenseMatrix::begin() const 
  {
    return m_val;
  }


  double* DenseMatrix::end()
  {
    return (m_val+m_size);
  }


  const double* DenseMatrix::end() const 
  {
    return (m_val + m_size);
  }


  double& DenseMatrix::diagonal(int i)
  {

    if (i < 0 || i >= m_rows)
      throw OutOfBoundsIndex("DenseMatrix::operator()", i);

    if (i < 0 || i >= m_cols)
      throw OutOfBoundsIndex("DenseMatrix::operator()", i);

    return m_val[data_index(i,i)];
  }

  const double& DenseMatrix::diagonal(int i) const
  {

    if (i < 0 || i >= m_rows)
      throw OutOfBoundsIndex("DenseMatrix::operator()", i);

    if (i < 0 || i >= m_cols)
      throw OutOfBoundsIndex("DenseMatrix::operator()", i);

    return m_val[data_index(i,i)];
  }


  int DenseMatrix::getSize() const 
  {
    return m_size;
  }

  int DenseMatrix::getNrows() const 
  {
    return m_rows;
  }

  int DenseMatrix::getNcols() const 
  {
    return m_cols;
  }


  DenseMatrix::~DenseMatrix()
  {
    m_rows    = 0; 
    m_cols    = 0; 
    m_size    = 0;
    delete [] m_val;
    m_val = nullptr;
  }


  double& DenseMatrix::operator() (int i, int j)
  {
    if (i < 0 || i >= m_rows)
      throw OutOfBoundsIndex("DenseMatrix::operator()", i);

    if (j < 0 || j >= m_cols)
      throw OutOfBoundsIndex("DenseMatrix::operator()", j);

    return m_val[this->data_index(i,j)];
  }

  const double& DenseMatrix::operator() (int i, int j) const
  {

    if (i < 0 || i >= m_rows)
      throw OutOfBoundsIndex("DenseMatrix::operator()", i);

    if (j < 0 || j >= m_cols)
      throw OutOfBoundsIndex("DenseMatrix::operator()", j);
 
    return m_val[this->data_index(i,j)];
  }




  std::ostream& operator << (std::ostream& out, const FEM::DenseMatrix& mat)
  {
    int width = 8;

    // Column Indices
    for (int jcol = 0; jcol < mat.getDimensions().second; ++jcol)
    {
      out << std::setw(width) << jcol << " ";
    }
    out << '\n';


    for (int irow = 0; irow < mat.getDimensions().first; ++irow)
    {
      // Row Indices
      out << irow << " " << "[";
      for (int jcol = 0; jcol < mat.getDimensions().second; ++jcol)
      {
        out << std::setw(width) << mat.value(irow, jcol) << " ";
      }
      out << "]\n";
    }

    return out;
  }

}

