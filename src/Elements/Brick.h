#ifndef _FEM_BRICK_INCLUDED_
#define _FEM_BRICK_INCLUDED_ 

#include "Node/Node.h"
#include <vector>
#include <initializer_list>
//
namespace FEM
{

  class Brick
  {
    public:
      Brick()                   = default;
      Brick(const Brick&  other);

      Brick& operator= (const Brick&  that);

      Brick            (      Brick&& other) = delete;
      Brick& operator= (      Brick&& that ) = delete;

      const Node3D& operator[] ( int i) const;
            Node3D& operator[] ( int i);

      int   getNumberOfNodes() const;
      void  addNode(const Node3D& node);
      const Node3D& getNode(int id) const;
      const std::vector<int> getNodeLabels() const;


    private:
      int m_label = -1;
      int nnodes  =  8;
      std::vector<const Node3D*> m_nodes;
  };

}



#endif
