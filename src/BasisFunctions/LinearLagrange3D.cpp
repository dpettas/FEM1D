#include "BasisFunctions/LinearLagrange3D.h"

namespace FEM 
{

  void LinearLagrange3DBFunction::set_diff_tolerance(double eps)
  {
    _phi[0].set_diff_tolerance(eps);
    _phi[1].set_diff_tolerance(eps);
    _phi[2].set_diff_tolerance(eps);
    _phi[3].set_diff_tolerance(eps);
  }

  LinearLagrange3DBFunction::LinearLagrange3DBFunction()
  {
    _phi = new BFunction3D [nbf];


    _phi[0].set([](double ksi, double eta, double zeta) 
        { 
          LinearLagrange1DBFunction lbf;
          auto phi0  = lbf.phi(0);
          auto phi1  = lbf.phi(1);
          return phi0(ksi) * phi0(eta) * phi0(zeta);
        } );

    _phi[1].set([](double ksi, double eta, double zeta) 
        { 
          LinearLagrange1DBFunction lbf;
          auto phi0  = lbf.phi(0);
          auto phi1  = lbf.phi(1);
          return phi1(ksi) * phi0(eta) * phi0(zeta);
        } );

    _phi[2].set([](double ksi, double eta, double zeta) 
        { 
          LinearLagrange1DBFunction lbf;
          auto phi0  = lbf.phi(0);
          auto phi1  = lbf.phi(1);
          return phi0(ksi) * phi1(eta) * phi0(zeta);
        } );

    _phi[3].set([](double ksi, double eta, double zeta) 
        { 
          LinearLagrange1DBFunction lbf;
          auto phi0  = lbf.phi(0);
          auto phi1  = lbf.phi(1);
          return phi1(ksi) * phi1(eta) * phi0(zeta);
        } );

    _phi[4].set([](double ksi, double eta, double zeta) 
        { 
          LinearLagrange1DBFunction lbf;
          auto phi0  = lbf.phi(0);
          auto phi1  = lbf.phi(1);
          return phi0(ksi) * phi0(eta) * phi1(zeta);
        } );
    
    _phi[5].set([](double ksi, double eta, double zeta) 
        { 
          LinearLagrange1DBFunction lbf;
          auto phi0  = lbf.phi(0);
          auto phi1  = lbf.phi(1);
          return phi1(ksi) * phi0(eta) * phi1(zeta);
        } );
    
    _phi[6].set([](double ksi, double eta, double zeta) 
        { 
          LinearLagrange1DBFunction lbf;
          auto phi0  = lbf.phi(0);
          auto phi1  = lbf.phi(1);
          return phi0(ksi) * phi1(eta) * phi1(zeta);
        } );
    
    _phi[7].set([](double ksi, double eta, double zeta) 
        { 
          LinearLagrange1DBFunction lbf;
          auto phi0  = lbf.phi(0);
          auto phi1  = lbf.phi(1);
          return phi0(ksi) * phi1(eta) * phi1(zeta);
        } );


  }

  int LinearLagrange3DBFunction::size() const 
  {
    return nbf;
  }

  BFunction3D& LinearLagrange3DBFunction::phi(int i)
  {
    if ( i < 0 || i >= nbf)
      throw OutOfBoundsIndex("LinearLagrangeBFunction::phi",i,0,nbf);

    return _phi[i];
  }

  LinearLagrange3DBFunction::~LinearLagrange3DBFunction()
  {
    delete [] _phi;
    _phi = nullptr;
  }
}
