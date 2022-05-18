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




    private:
      int m_label = -1;
      std::vector<Node3D*> m_nodes; 



  };

}



#endif
