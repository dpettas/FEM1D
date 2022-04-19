#ifndef _FEM1D_POINT_INCLUDED_
#define _FEM1D_POINT_INCLUDED_

namespace FEM
{

  class Point
  {

    public:
      virtual const int&    numberOfDimensions() const = 0;
      virtual const double* getCoordinates() const = 0;
      virtual const double  distance(const Point& other) const = 0;


    private:


  };
}




#endif
