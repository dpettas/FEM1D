#ifndef _FEM_BRICK_INCLUDED_
#define _FEM_BRICK_INCLUDED_ 

#include "Node3D.h"

#include <vector>

namespace FEM 
{

  class Brick 
  {
    public: 
      Brick() = default;
      Brick(const Brick& other) = default;

      int getNumberOfNodes() const;

      void addNode(const Node3D& node);


    private:
      int m_label = -1;
      int nnodes  =  8;
      std::vector<const Node3D*> m_nodes; 
  };

}



#endif
