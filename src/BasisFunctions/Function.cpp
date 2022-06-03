#include "BasisFunctions/Function.h"
#include <sys/wait.h>

double FEM::BasisFunction::eps = 1e-6;

namespace FEM 
{

  BasisFunction::BasisFunction(std::function<double(double)> fn_1)
  {
    fn = [&fn_1] (double ksi, double eta, double zeta)
      { return fn_1(ksi) * 1.0 * 1.0;};
  }

  BasisFunction::BasisFunction(std::function<double(double,double)> fn_2)
  {
    fn = [&fn_2] (double ksi, double eta, double zeta)
      { return fn_2(ksi,eta) * 1.0;};
  }

  BasisFunction::BasisFunction(std::function<double(double,double,double)> fn_3)
  {
    fn = [&fn_3] (double ksi, double eta, double zeta)
      { return fn_3(ksi,eta,zeta);};
  }


}

