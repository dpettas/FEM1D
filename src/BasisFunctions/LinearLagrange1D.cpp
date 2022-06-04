#include "BasisFunctions/LinearLagrange1D.h"

namespace FEM 
{

  void LinearLagrange1DBFunction::set_diff_tolerance(double eps)
  {
    _phi[0].set_diff_tolerance(eps);
    _phi[1].set_diff_tolerance(eps);
  }


  LinearLagrange1DBFunction::LinearLagrange1DBFunction()
  {
    _phi = new BFunction1D [nbf];

    _phi[0].set([](double ksi) { return 0.50 * (1.0 - ksi);} );
    _phi[1].set([](double ksi) { return 0.50 * (1.0 + ksi);} );

  }

  int LinearLagrange1DBFunction::size() const 
  {
    return nbf;
  }

  BFunction1D& LinearLagrange1DBFunction::phi(int i)
  {
    if ( i < 0 || i >= nbf)
      throw OutOfBoundsIndex("LinearLagrangeBFunction::phi",i,0,nbf);

    return _phi[i];
  }

  LinearLagrange1DBFunction::~LinearLagrange1DBFunction()
  {
    delete [] _phi;
    _phi = nullptr;
  }

}
