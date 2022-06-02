#include "LinearAlgebra/DenseMatrix.h"
#include "LinearAlgebra/exceptions.h"

namespace FEM 
{


  DenseMatrix::DenseMatrix(std::initializer_list<std::initializer_list<double>> ll)
  {
    int nrows = ll.size(); 
    int ncols = ll.begin()->size();

    // Check that all the rows has the same columns
    for (const std::initializer_list<double>& row : ll)
    {
      if( (int) row.size() != ncols) 
        throw NotSameNumberOfColumns("DenseMatrix::DenseMatrix(std::initializer_list<std::initializer_list<double>>)");
    }

    m_rows = nrows; 
    m_cols = ncols; 
    m_size = m_rows * m_cols; 
    m_val  = new double [m_size];

    int i = 0;
    for(auto row : ll)
    {
      int j = 0;
      for(auto val : row)
      {
        m_val[data_index(i,j)] = val;
      
        ++j; 
      }
      ++i;
    }


  }


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

  double& DenseMatrix::get(int i)
  {
    return *(m_val + i);
  }

  const double& DenseMatrix::get(int i) const 
  {
    return *(m_val + i);
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
      throw OutOfBoundsIndex("DenseMatrix::diagonal(int i)", i);

    if (i < 0 || i >= m_cols)
      throw OutOfBoundsIndex("DenseMatrix::diagonal(int i)", i);

    return m_val[data_index(i,i)];
  }

  const double& DenseMatrix::diagonal(int i) const
  {

    if (i < 0 || i >= m_rows)
      throw OutOfBoundsIndex("DenseMatrix::diagonal(int i)", i);

    if (i < 0 || i >= m_cols)
      throw OutOfBoundsIndex("DenseMatrix::diagonal(int i)", i);

    return m_val[data_index(i,i)];
  }


  int DenseMatrix::getSize() const 
  {
    return m_size;
  }

  int DenseMatrix::size() const 
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

  DenseMatrixValues DenseMatrix::operator() (const Indices& idx_x, const Indices& idx_y)
  {

    auto hasDublication = [](const Indices& idx) 
    { return static_cast<int>(std::unordered_set(idx.begin(),idx.end()).size()) != idx.size(); };


    if ( idx_x.size() != idx_y.size() )
      throw NotEqualBalancedArrays("DenseMatrix::operator()(const Indices& idx_x, const Indices& idx_y)");

    if (hasDublication(idx_x))
      throw DublicatedIndex("DenseMatrix::operator() (const Indices&, const Indices&) check i. ");

    if (hasDublication(idx_y))
      throw DublicatedIndex("DenseMatrix::operator() (const Indices&, const Indices&) chek j. ");
    

    DenseMatrixValues out;
    int nx= idx_x.size();
    int ny= idx_y.size();

    for ( int ii = 0; ii < nx; ++ii )
    {
      for ( int jj = 0; jj < ny; ++jj )
      {
        int i = idx_x.get(ii);
        int j = idx_y.get(jj);

        if ( i < 0 || i > getNrows() )
          throw OutOfBoundsIndex("DenseMatrix::operator()(const Indices&, const Indices&)",i);

        if ( j < 0 || j > getNcols() )
          throw OutOfBoundsIndex("DenseMatrix::operator()(const Indices&, const Indices&)",j);

        out.push_back( &m_val[data_index(i,j)] );
      }
    }


    return out;
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

