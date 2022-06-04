#include "BasisFunctions/LinearLagrange1D.h"

namespace FEM 
{

  void LinearLagrangeBFunction::set_diff_tolerance(double eps)
  {
    _phi[0].set_diff_tolerance(eps);
    _phi[1].set_diff_tolerance(eps);
  }


  LinearLagrangeBFunction::LinearLagrangeBFunction()
  {
    _phi = new BFunction1D [nbf];

    _phi[0].set([](double x) { return 0.50 * (1.0 - x);} );
    _phi[1].set([](double x) { return 0.50 * (1.0 + x);} );

  }

  int LinearLagrangeBFunction::size() const 
  {
    return nbf;
  }

  BFunction1D& LinearLagrangeBFunction::phi(int i)
  {
    if ( i < 0 || i >= nbf)
      throw OutOfBoundsIndex("LinearLagrangeBFunction::phi",i,0,nbf);

    return _phi[i];
  }

  LinearLagrangeBFunction::~LinearLagrangeBFunction()
  {
    delete [] _phi;
    _phi = nullptr;
  }

}
