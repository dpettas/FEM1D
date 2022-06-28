#include "Mesh/Mesh.h"
#include <cctype>
#include <vector>

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
    connectivity();
  }

  Mesh::Mesh(const Mesh& other)
  {
    _nxel = other._nxel; 
    _nyel = other._nyel; 
    _nzel = other._nzel;

    _nnx  = other._nnx; 
    _nny  = other._nny;
    _nnz  = other._nnz;
    
    for (const Node3D& n : other.getNodes())
      _nodes.push_back(n);

    for (const Brick& elem : other.getElements() )
    {
      int nn = elem.getNumberOfNodes();
     

      Brick nelement;

      for (int i = 0; i < nn; ++i )
      {
        int label = elem.getNode(i).getLabel(); // other nodes
        nelement.addNode( _nodes[label] ); 
      }
      _elements.push_back( nelement  );
    }
  }


  void Mesh::toAsciiTecplot(const char* filename) const
  {
    int nn = getNumberOfNodes();
    int ne = getNumberOfElements(); 
    std::vector<double> x;
    std::vector<double> y;
    std::vector<double> z;
    std::vector<std::vector<int>> connectivity;
 
    for (const Node3D& n : getNodes())
    {
      x.push_back(n.component(0));
      y.push_back(n.component(1));
      z.push_back(n.component(2));
    }


    for (const Brick& elem : getElements() )
    {
      connectivity.push_back( elem.getNodeLabels() );
    }




    IO::AsciiTecplot tecfile (filename);
    tecfile.open();

    tecfile.setNumberOfPoints ( nn );
    tecfile.setNumberOfElemets( ne );

    tecfile.addFieldValue("X",x);
    tecfile.addFieldValue("Y",y);
    tecfile.addFieldValue("Z",z);
    tecfile.addConnectivity(connectivity);
    tecfile.write();
    tecfile.close();
  }


  void Mesh::toAsciiTecplot(const std::string& filename) const 
  {
    toAsciiTecplot(filename.c_str());
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

  const Brick& Mesh::getElement(int id) const
  {
    return _elements.at(id);
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

  void Mesh::connectivity()
  {
    for (int i = 0; i < _nzel; ++i)
    {
      for (int j = 0; j < _nyel; ++j)
      {
        for (int k = 0; k < _nxel; ++k)
        {
          int NBF_1d = 2;
          int jj     = (NBF_1d-1)*(k-0) + 0;
          int surf   = i -0;
          int level  = j -0;
          int mnd    = _nnx * _nny;
          int nnd    = _nnx;


          int element_id;
          Brick  element;

          auto node_id = [mnd, nnd](int surf_, int level_, int loc_)
          {
            return surf_ * mnd + level_ * nnd + loc_;
          };

          element_id  = node_id(surf + 0, level + 0, jj + 0);
          element.addNode( this->getNode(element_id));

          element_id  = node_id(surf + 0, level + 0, jj + 1);
          element.addNode( this->getNode(element_id));
        
          element_id  = node_id(surf + 0, level + 1, jj + 1);
          element.addNode( this->getNode(element_id));

          element_id  = node_id(surf + 0, level + 1, jj + 0);
          element.addNode( this->getNode(element_id));

          element_id  = node_id(surf + 1, level + 0, jj + 0);
          element.addNode( this->getNode(element_id));

          element_id  = node_id(surf + 1, level + 0, jj + 1);
          element.addNode( this->getNode(element_id));

          element_id  = node_id(surf + 1, level + 1, jj + 1);
          element.addNode( this->getNode(element_id));

          element_id  = node_id(surf + 1, level + 1, jj + 0);
          element.addNode( this->getNode(element_id));

       
          _elements.push_back(element);
        }
      }
    
    }
  }




}
