#ifndef _FEM_MESH_INCLUDED_
#define _FEM_MESH_INCLUDED_ 

#include "Node/Node.h"
#include "Elements/Brick.h"
#include "export/AsciiTecplot.h"

#include <algorithm>
#include <iostream>

namespace FEM 
{
  class Mesh 
  {
    public: 
      Mesh() = default; 
      Mesh(int nxel, int nyel, int nzel);

      Mesh(const Mesh& other);
      Mesh(      Mesh&& other);

      int                        getNumberOfNodes()             const;  
      int                        getNumberOfElements()          const;  
      int                        getNodeID(int i, int j, int k) const;
      
      const Node3D&              getNode   (int id) const;
      const Brick&               getElement(int id) const;

      const std::vector<Node3D>& getNodes()         const;
      const std::vector<Brick>&  getElements()      const;

      Mesh& scale    (double _scale0, double _scale1, double _scale2);
      Mesh& translate(double _trans0, double _trans1, double _trans2);


      Mesh& operator= (const Mesh&  that);
      Mesh& operator= (      Mesh&& that);

      bool operator==(const Mesh& other);
      bool operator!=(const Mesh& other);

      void toAsciiTecplot(const char* fiilename)    const;
      void toAsciiTecplot(const std::string& filename) const;


    private: 
      void createNodes();
      void connectivity();

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
