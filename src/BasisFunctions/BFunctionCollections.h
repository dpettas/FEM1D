#ifndef _FEM_BFUNCTIONCOLLECTIONS_INCLUDED_ 
#define _FEM_BFUNCTIONCOLLECTIONS_INCLUDED_ 

#include "BFunctionCollection.h"

namespace FEM::COLLECTION 
{

  static BFunctionCollection LinearLagrange1D = 
  {
    BFunction1D ( [] (double ksi) { return 0.50 * (1.0 - ksi);} ),
    BFunction1D ( [] (double ksi) { return 0.50 * (1.0 + ksi);} )
  };


  static BFunctionCollection LinearLagrange2D = 
  {
    BFunction2D ( [] (double ksi, double eta) { return 0.50 * (1.0 - ksi) * 0.50 * (1.0 - eta);} ),
    BFunction2D ( [] (double ksi, double eta) { return 0.50 * (1.0 + ksi) * 0.50 * (1.0 - eta);} ),
    BFunction2D ( [] (double ksi, double eta) { return 0.50 * (1.0 - ksi) * 0.50 * (1.0 + eta);} ),
    BFunction2D ( [] (double ksi, double eta) { return 0.50 * (1.0 + ksi) * 0.50 * (1.0 + eta);} )
  };
  
  static BFunctionCollection LinearLagrange3D = 
  {
    BFunction3D ( [] (double ksi, double eta, double zeta) { return 0.50 * (1.0 - ksi) * 0.50 * (1.0 - eta) * 0.50 * (1.0 - zeta);} ),
    BFunction3D ( [] (double ksi, double eta, double zeta) { return 0.50 * (1.0 + ksi) * 0.50 * (1.0 - eta) * 0.50 * (1.0 - zeta);} ),
    BFunction3D ( [] (double ksi, double eta, double zeta) { return 0.50 * (1.0 - ksi) * 0.50 * (1.0 + eta) * 0.50 * (1.0 - zeta);} ),
    BFunction3D ( [] (double ksi, double eta, double zeta) { return 0.50 * (1.0 + ksi) * 0.50 * (1.0 + eta) * 0.50 * (1.0 - zeta);} ),
    BFunction3D ( [] (double ksi, double eta, double zeta) { return 0.50 * (1.0 - ksi) * 0.50 * (1.0 - eta) * 0.50 * (1.0 + zeta);} ),
    BFunction3D ( [] (double ksi, double eta, double zeta) { return 0.50 * (1.0 + ksi) * 0.50 * (1.0 - eta) * 0.50 * (1.0 + zeta);} ),
    BFunction3D ( [] (double ksi, double eta, double zeta) { return 0.50 * (1.0 - ksi) * 0.50 * (1.0 + eta) * 0.50 * (1.0 + zeta);} ),
    BFunction3D ( [] (double ksi, double eta, double zeta) { return 0.50 * (1.0 + ksi) * 0.50 * (1.0 + eta) * 0.50 * (1.0 + zeta);} ),

  };
  
}

#endif
