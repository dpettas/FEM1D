#include "BasisFunctions/Function.h"
#include <sys/wait.h>

double FEM::BasisFunction::eps = 1e-6;

namespace FEM 
{


  BasisFunction::BasisFunction(_func fn_3)
  {
    fn = fn_3;
  }

  BasisFunction::_func BasisFunction::function()
  {
    return fn;
  }

  double BasisFunction::value(double ksi, double eta, double zeta)
  {
    return fn(ksi,eta,zeta);
  }

  double BasisFunction::dksi(double ksi, double eta, double zeta)
  {
    auto der = [this](double _ksi, double _eta, double _zeta)
      { return ( fn(_ksi+eps, _eta, _zeta) - fn(_ksi, _eta, _zeta) )/eps;};

    return 1.0;
  }

}

