#ifndef _FEM_FUNCTION_INCLUDED_
#define _FEM_FUNCTION_INCLUDED_ 

#include <functional>
#include <iostream>

namespace FEM 
{

  class BasisFunction
  {
    private:
      using _func = std::function<double(double,double,double)>;

      _func fn;

    public: 

      static double eps; 
      static void set_tolerance(double _eps) { eps = _eps; }

      BasisFunction() = delete;
      explicit BasisFunction(_func fn_3);

      double value(double ksi = 0.0, double eta = 0.0, double zeta = 0.0);
      double dksi (double ksi = 0.0, double eta = 0.0, double zeta = 0.0);
      double deta (double ksi = 0.0, double eta = 0.0, double zeta = 0.0);
      double dzeta(double ksi = 0.0, double eta = 0.0, double zeta = 0.0);
      _func function();
  };

}






#endif
