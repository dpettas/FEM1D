#ifndef _FEM1D_NODE_INCLUDED_
#define _FEM1D_NODE_INCLUDED_

#include "Point.h"
#include "Point1D.h"

namespace FEM{


  class Node{

    public:

      Node();
      Node(int node_id_, const Point* p_);
      Node(int node_id_, double x_);
      Node(const Node& rhs);
      ~Node();

      const Point* getPoint()  const { return p;};
      Point*       getPoint()        { return p;};
      const int    getNodeId() const { return node_id;}
      int          getNodeId()       { return node_id;}


      bool hasTheSameId(const Node& other  );
      void setNodeId   (const int& node_id_);
      void setLocation (const double& x_   );
      

    private:
      int    node_id = -1;
      bool   point_created = false;
      Point* p = nullptr;

  };

}





#endif
