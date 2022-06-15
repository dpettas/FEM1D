#ifndef _FEM_GPOINTCOLLECTIONS_INCLUDED_ 
#define _FEM_GPOINTCOLLECTIONS_INCLUDED_ 

#include <cmath>
#include "Point/Point.h"
#include "Integration/GPoint.h"
#include "Integration/GPointCollection.h"
#include "Integration/functions.h"

namespace FEM::COLLECTIONS
{
  using std::sqrt;

  static GPointCollection GPoints3_1D = {
                                          GPoint( 5.0/9.0,  -sqrt(3.0/5.0)   ),
                                          GPoint( 8.0/9.0,            0.0    ),
                                          GPoint( 5.0/9.0,  +sqrt(3.0/5.0)   ),
                                       };


  static GPointCollection GPoints9_2D = {
                                          makeGPoint( GPoints3_1D[0], GPoints3_1D[0]),
                                          makeGPoint( GPoints3_1D[0], GPoints3_1D[1]),
                                          makeGPoint( GPoints3_1D[0], GPoints3_1D[2]),

                                          makeGPoint( GPoints3_1D[1], GPoints3_1D[0]),
                                          makeGPoint( GPoints3_1D[1], GPoints3_1D[1]),
                                          makeGPoint( GPoints3_1D[1], GPoints3_1D[2]),

                                          makeGPoint( GPoints3_1D[2], GPoints3_1D[0]),
                                          makeGPoint( GPoints3_1D[2], GPoints3_1D[1]),
                                          makeGPoint( GPoints3_1D[2], GPoints3_1D[2]),
                                       };

  static GPointCollection GPoints27_3D= {
                                          makeGPoint( GPoints3_1D[0], GPoints3_1D[0], GPoints3_1D[0]),
                                          makeGPoint( GPoints3_1D[0], GPoints3_1D[0], GPoints3_1D[1]),
                                          makeGPoint( GPoints3_1D[0], GPoints3_1D[0], GPoints3_1D[2]),

                                          makeGPoint( GPoints3_1D[0], GPoints3_1D[1], GPoints3_1D[0]),
                                          makeGPoint( GPoints3_1D[0], GPoints3_1D[1], GPoints3_1D[1]),
                                          makeGPoint( GPoints3_1D[0], GPoints3_1D[1], GPoints3_1D[2]),

                                          makeGPoint( GPoints3_1D[0], GPoints3_1D[2], GPoints3_1D[0]),
                                          makeGPoint( GPoints3_1D[0], GPoints3_1D[2], GPoints3_1D[1]),
                                          makeGPoint( GPoints3_1D[0], GPoints3_1D[2], GPoints3_1D[2]),

                                          
                                          makeGPoint( GPoints3_1D[1], GPoints3_1D[0], GPoints3_1D[0]),
                                          makeGPoint( GPoints3_1D[1], GPoints3_1D[0], GPoints3_1D[1]),
                                          makeGPoint( GPoints3_1D[1], GPoints3_1D[0], GPoints3_1D[2]),

                                          makeGPoint( GPoints3_1D[1], GPoints3_1D[1], GPoints3_1D[0]),
                                          makeGPoint( GPoints3_1D[1], GPoints3_1D[1], GPoints3_1D[1]),
                                          makeGPoint( GPoints3_1D[1], GPoints3_1D[1], GPoints3_1D[2]),

                                          makeGPoint( GPoints3_1D[1], GPoints3_1D[2], GPoints3_1D[0]),
                                          makeGPoint( GPoints3_1D[1], GPoints3_1D[2], GPoints3_1D[1]),
                                          makeGPoint( GPoints3_1D[1], GPoints3_1D[2], GPoints3_1D[2]),


                                          makeGPoint( GPoints3_1D[2], GPoints3_1D[0], GPoints3_1D[0]),
                                          makeGPoint( GPoints3_1D[2], GPoints3_1D[0], GPoints3_1D[1]),
                                          makeGPoint( GPoints3_1D[2], GPoints3_1D[0], GPoints3_1D[2]),

                                          makeGPoint( GPoints3_1D[2], GPoints3_1D[1], GPoints3_1D[0]),
                                          makeGPoint( GPoints3_1D[2], GPoints3_1D[1], GPoints3_1D[1]),
                                          makeGPoint( GPoints3_1D[2], GPoints3_1D[1], GPoints3_1D[2]),

                                          makeGPoint( GPoints3_1D[2], GPoints3_1D[2], GPoints3_1D[0]),
                                          makeGPoint( GPoints3_1D[2], GPoints3_1D[2], GPoints3_1D[1]),
                                          makeGPoint( GPoints3_1D[2], GPoints3_1D[2], GPoints3_1D[2]),
                                       };




}



#endif
