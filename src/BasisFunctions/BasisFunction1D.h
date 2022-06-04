#ifndef _FEM_BASISFUNCTION1D_INCLUDED_
#define _FEM_BASISFUNCTION1D_INCLUDED_ 

#include <functional>

namespace FEM 
{

class BasisFunction1D
{

  public: 
    using _func = std::function<double(double)>;

    void set_diff_tolerance(double eps);

    BasisFunction1D() = delete;
    BasisFunction1D(_func _basisFunction );
    BasisFunction1D(const BasisFunction1D& other);
    BasisFunction1D& operator = (const BasisFunction1D& that);

    double operator () (double x1);




    int dimensionality() const;
    _func dx1();

  

  private:
    double _eps = 1e-6;
    _func m_basisFunction;

};

}




#endif
