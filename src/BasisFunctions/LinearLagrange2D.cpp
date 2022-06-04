#include "BasisFunctions/LinearLagrange2D.h"



namespace FEM 
{

  void LinearLagrange2DBFunction::set_diff_tolerance(double eps)
  {
    _phi[0].set_diff_tolerance(eps);
    _phi[1].set_diff_tolerance(eps);
    _phi[2].set_diff_tolerance(eps);
    _phi[3].set_diff_tolerance(eps);
  }

  LinearLagrange2DBFunction::LinearLagrange2DBFunction()
  {
    _phi = new BFunction2D [nbf];


    _phi[0].set([](double ksi, double eta) 
        { 
          LinearLagrange1DBFunction lbf;
          auto phi0  = lbf.phi(0);
          auto phi1  = lbf.phi(1);
          return phi0(ksi)*phi0(eta);
        } );

    _phi[1].set([](double ksi, double eta) 
        { 
          LinearLagrange1DBFunction lbf;
          auto phi0  = lbf.phi(0);
          auto phi1  = lbf.phi(1);
          return phi1(ksi)*phi0(eta);
        } );

    _phi[2].set([](double ksi, double eta) 
        { 
          LinearLagrange1DBFunction lbf;
          auto phi0  = lbf.phi(0);
          auto phi1  = lbf.phi(1);
          return phi0(ksi)*phi1(eta);
        } );

    _phi[3].set([](double ksi, double eta) 
        { 
          LinearLagrange1DBFunction lbf;
          auto phi0  = lbf.phi(0);
          auto phi1  = lbf.phi(1);
          return phi1(ksi)*phi1(eta);
        } );


  }

  int LinearLagrange2DBFunction::size() const 
  {
    return nbf;
  }

  BFunction2D& LinearLagrange2DBFunction::phi(int i)
  {
    if ( i < 0 || i >= nbf)
      throw OutOfBoundsIndex("LinearLagrangeBFunction::phi",i,0,nbf);

    return _phi[i];
  }

  LinearLagrange2DBFunction::~LinearLagrange2DBFunction()
  {
    delete [] _phi;
    _phi = nullptr;
  }
}
