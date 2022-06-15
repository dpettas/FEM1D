#include "Integration/functions.h"

namespace FEM 
{

FEM::GPoint2D makeGPoint( FEM::GPoint1D gs1, FEM::GPoint1D gs2 )
{
  return FEM::GPoint2D( gs1.weight() * gs2.weight(), 
                        gs1.get()[0], 
                        gs2.get()[0]);
}


FEM::GPoint3D makeGPoint( FEM::GPoint1D gs1, FEM::GPoint1D gs2, FEM::GPoint1D gs3 )
{
  return FEM::GPoint3D( gs1.weight() * gs2.weight() * gs3.weight(), 
                        gs1.get()[0], 
                        gs2.get()[0], 
                        gs3.get()[0]);
}


FEM::GPoint3D makeGPoint( FEM::GPoint2D gs1, FEM::GPoint1D gs2)
{
  return FEM::GPoint3D( gs1.weight() * gs2.weight(), 
                        gs1.get()[0], 
                        gs1.get()[1], 
                        gs2.get()[0]);
}


FEM::GPoint3D makeGPoint( FEM::GPoint1D gs1, FEM::GPoint2D gs2)
{
  return FEM::GPoint3D( gs1.weight() * gs2.weight(), 
                        gs1.get()[0], 
                        gs2.get()[0], 
                        gs2.get()[1]);
}


}
