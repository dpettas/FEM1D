#ifndef _FEM1D_POINT3D_INCLUDED_
#define _FEM1D_POINT3D_INCLUDED_

#include <iostream>
#include <cmath>
#include <initializer_list>

namespace FEM{

  class Point3D 
  {
    public:


      Point3D()               = default;
      Point3D(const Point3D&) = default;
      Point3D(double x, double y = 0.0, double z = 0.0);

      Point3D(Point3D&& other) = delete;

      Point3D& operator = (const Point3D& that) = default;
      Point3D& operator = (Point3D&& that) = delete;


      Point3D operator+ (const Point3D& other);
      Point3D operator- (const Point3D& other);

      double& getX(); 
      const double& getX() const;

      double& getY(); 
      const double& getY() const;

      double& getZ(); 
      const double& getZ() const;


      double distanceFrom(const Point3D& other);

      void setX(double x);
      void setY(double y);
      void setZ(double z);

      bool operator == (const Point3D& other);
      bool operator != (const Point3D& other);


    private:
      double m_x = 0.0; 
      double m_y = 0.0;
      double m_z = 0.0;
  };


  std::ostream& operator << (std::ostream& out, const Point3D& obj);
}

#endif // !






