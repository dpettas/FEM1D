#ifndef _FEM_GPOINTCOLLECTIONS_INCLUDED_ 
#define _FEM_GPOINTCOLLECTIONS_INCLUDED_ 

#include <cmath>
#include "Point/Point.h"
#include "Integration/GPoint.h"
#include "Integration/GPointCollection.h"

namespace FEM::COLLECTIONS
{
  using std::sqrt;

  // Point<double> p = Point<double>( - sqrt(3.0/5.0) );
  // static GPointCollection GPoints3_1D = {
  //                                         GPoint( 5.0/9.0,  -sqrt(3.0/5.0) ),
  //                                         GPoint( 8.0/9.0,            0.0  ),
  //                                         GPoint( 5.0/9.0,  +sqrt(3.0/5.0) )
  //                                      };
  //
  //
  // static GPointCollection GPoints9_2D = {
  //                                         GPoint( 25.0/81.0,  -sqrt(3.0/5.0), -sqrt(3.0/5.0) ),
  //                                         GPoint( 40.0/81.0,  -sqrt(3.0/5.0),           0.0  ),
  //                                         GPoint( 25.0/81.0,  -sqrt(3.0/5.0), +sqrt(3.0/5.0) ),
  //
  //                                         GPoint( 40.0/81.0,            0.0 , -sqrt(3.0/5.0) ),
  //                                         GPoint( 64.0/81.0,            0.0 ,           0.0  ),
  //                                         GPoint( 40.0/81.0,            0.0 , +sqrt(3.0/5.0) ),
  //
  //                                         GPoint( 25.0/81.0,  +sqrt(3.0/5.0), -sqrt(3.0/5.0) ),
  //                                         GPoint( 40.0/81.0,  +sqrt(3.0/5.0),           0.0  ),
  //                                         GPoint( 25.0/81.0,  +sqrt(3.0/5.0), +sqrt(3.0/5.0) ),
  //                                      };

}



#endif
