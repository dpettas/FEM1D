#ifndef _FEM_BFUNCTIONCOLLECTIONS_INCLUDED_ 
#define _FEM_BFUNCTIONCOLLECTIONS_INCLUDED_ 

#include "BFunctionCollection.h"

namespace FEM::COLLECTION 
{

  static BFunctionCollection LinearLagrange1DBFunction = 
  {
    BFunction1D ( [] (double ksi) { return 0.50 * (1.0 - ksi);} ),
    BFunction1D ( [] (double ksi) { return 0.50 * (1.0 + ksi);} )
  };
  
}

#endif
