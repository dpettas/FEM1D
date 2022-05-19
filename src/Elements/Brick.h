#ifndef _FEM_BRICK_INCLUDED_
#define _FEM_BRICK_INCLUDED_ 

#include "Node3D.h"
#include "Mesh3D.h"

#include <vector>

namespace FEM 
{

  class Brick 
  {
    public: 
      Brick() = default;
      Brick(const Brick& other) = default;
      Brick(Mesh3D::PolynomialOrder order = Mesh3D::PolynomialOrder::Linear){};

      int getNumberOfNodes() const;
      void addNode(const Node3D& node);


    private:
      int m_label = -1;
      Mesh3D::PolynomialOrder m_order;
      std::vector<Node3D*> m_nodes; 
  };

}



#endif
