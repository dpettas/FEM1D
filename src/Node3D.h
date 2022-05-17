#ifndef _NODE3D_INCLUDED_
#define _NODE3D_INCLUDED_

#include "Point3D.h"
#include <iostream>

namespace FEM{
  class Node3D : public Point3D
  {
    public: 
      Node3D() = default;
      Node3D(const Node3D&) = default;
      Node3D(int label, double x = 0.0, double y = 0.0, double z = 0.0);
      Node3D(int label, const Point3D& p);

      int& getLabel();
      const int& getLabel() const;

      void setLabel(int label);

    private:
      int m_label = 0;
  };

  std::ostream& operator << (std::ostream& out, const Node3D& obj);

}

#endif



