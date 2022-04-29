#ifndef _FEM1D_MESH1D_INCLUDED_
#define _FEM1D_MESH1D_INCLUDED_

#include "Node.h"
#include <iostream>



namespace FEM{






  class Mesh1D{

    public:


      static Node* IDENTITY(int num_nodes, const Node* nodes){ return const_cast<Node*>(nodes);}





      Mesh1D();
      Mesh1D(double low_, double max_, int num_nodes_);
      Mesh1D(const Mesh1D& rhs);
      ~Mesh1D();

      const double& getLowBound()   const { return xlow;     }
      const double& getUpperBound() const { return xmax;     }
      const    int& getNumNodes()   const { return num_nodes;}
      const Node*   getNodes()      const { return nodes;    }
      

      void setSpaceModifier( Node* (*mod)(int, const Node*) );



    private:
      void createNodes();
    
      int            num_nodes;
      double         xlow;
      double         xmax;
      Node*          nodes = nullptr;



  };


}



#endif
