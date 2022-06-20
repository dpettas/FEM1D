#include "Mesh/Mesh.h"
#include <cctype>

namespace FEM 
{
  Mesh::Mesh(int nxel, int nyel, int nzel) : 
    _nxel(nxel),
    _nyel(nyel),
    _nzel(nzel)
  {
    int nbf = 2;
    _nnx = (nbf-1) * _nxel + 1;
    _nny = (nbf-1) * _nyel + 1;
    _nnz = (nbf-1) * _nzel + 1;

    createNodes();
  }


  int Mesh::getNumberOfNodes() const 
  {
    return _nnx * _nny * _nnz;
  }

  int Mesh::getNumberOfElements() const
  {
    return _nxel * _nyel * _nzel;
  }

  int Mesh::getNodeID(int i, int j, int k) const
  {
    return k * _nnx * _nny + j * _nnx + i;
  }

  const std::vector<Node3D>& Mesh::getNodes() const 
  {
    return _nodes;
  }

  const std::vector<Brick>& Mesh::getElements() const
  {
    return _elements;
  }

  const Node3D& Mesh::getNode(int id) const
  { 
    return _nodes.at(id);
  }

  Mesh& Mesh::scale(double _scale0, double _scale1, double _scale2)
  {
    for(Node3D& node : _nodes)
    {
      node.component(0) *= _scale0;
      node.component(1) *= _scale1;
      node.component(2) *= _scale2;
    }

   
    return *this;
  }
  
  Mesh& Mesh::translate(double _trans0, double _trans1, double _trans2)
  {
    for(Node3D& node : _nodes)
    {
      node.component(0) += _trans0;
      node.component(1) += _trans1;
      node.component(2) += _trans2;
    }
   
    return *this;
  }
    


  void Mesh::createNodes() 
  {
    int nbf = 2;

    for (int i = 0; i < _nnx; ++i)
    {
      for (int j = 0; j < _nny; ++j)
      {
        for (int k = 0; k < _nnz; ++k)
        {
          int nodeid  = this->getNodeID(i,j,k);
          double x = (static_cast<double>(i))/_nxel;
          double y = (static_cast<double>(j))/_nyel;
          double z = (static_cast<double>(k))/_nzel;

          x /= (nbf-1);
          y /= (nbf-1);
          z /= (nbf-1);
        
          Node3D node {nodeid, x, y, z};
          _nodes.push_back(node);
        }
      }
    }

    // Sort by label
    std::sort(_nodes.begin(), 
              _nodes.end()  ,
              [] (const Node3D na, const Node3D nb)
              {
                return na.getLabel() < nb.getLabel();
              } );

  }
  
}
