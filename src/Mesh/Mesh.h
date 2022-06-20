#ifndef _FEM_MESH_INCLUDED_
#define _FEM_MESH_INCLUDED_ 

#include "Node/Node.h"
#include "Elements/Brick.h"

#include <algorithm>

namespace FEM 
{
  class Mesh 
  {
    public: 
      Mesh() = default; 
      Mesh(int nxel, int nyel, int nzel);

      Mesh(const Mesh& other);
      Mesh(      Mesh&& other);

      int                        getNumberOfNodes()    const;  
      int                        getNumberOfElements() const;  
      int                        getNodeID(int i, int j, int k) const;
      
      const Node3D&              getNode   (int id) const;
      const Brick&               getElement(int id) const;

      const std::vector<Node3D>& getNodes()         const;
      const std::vector<Brick>&  getElements()      const;

      Mesh& scale();
      Mesh& translate();

      void toAsciiTecplot(const char* fiilename)    const;

      Mesh& operator= (const Mesh&  that);
      Mesh& operator= (      Mesh&& that);

      bool operator==(const Mesh& other);
      bool operator!=(const Mesh& other);

      void createNodes();

    private: 
      int _nxel =  0;
      int _nyel =  0;
      int _nzel =  0;

      int _nnx  =  0;
      int _nny  =  0;
      int _nnz  =  0;

      std::vector<Node3D> _nodes;
      std::vector<Brick>  _elements;

  };
}




#endif
