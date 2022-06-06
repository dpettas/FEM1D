#ifndef _FEM_GPOINTCOLLECTIONS_INCLUDED_ 
#define _FEM_GPOINTCOLLECTIONS_INCLUDED_ 

#include <cmath>
#include "Integration/GPoint.h"
#include "Integration/GPointCollection.h"

namespace FEM::COLLECTIONS
{
  static GPointCollection GPoints3_1D = { 
                                          GPoint( 5.0/9.0,  -std::sqrt(3.0/5.0) ),
                                          GPoint( 8.0/9.0,                 0.0  ),
                                          GPoint( 5.0/9.0,  +std::sqrt(3.0/5.0) )
                                       };

}



#endif
