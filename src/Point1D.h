#ifndef _FEM1D_POINT1D_INCLUDED_
#define _FEM1D_POINT1D_INCLUDED_

#include "Point.h"
#include <cmath>
#include <iostream>

namespace FEM
{

  class Point1D : public Point
  {

    public:
      Point1D();
      ~Point1D();
      Point1D(double x_);

      Point1D(const Point1D& rhs);
      Point1D(const Point*& rhs);

      const int&    numberOfDimensions()   const;
      const double* getCoordinates() const;
      const double  distanceFrom( const Point& other) const;
      

    private:
      int num;
      double* xx;
  };
}




#endif
