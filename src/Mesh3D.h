#ifndef _FEM_MESH3D_INCLUDED_
#define _FEM_MESH3D_INCLUDED_ 

#include "Node3D.h"
#include "Elements/Brick.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <iomanip>
#include <functional>

namespace FEM
{
  class Mesh3D 
  {
    public: 

      enum class PolynomialOrder{
        Linear    = 2,
        Quadratic = 3, 
        Cubic     = 4,
      };


      Mesh3D() = default;
      Mesh3D(const Mesh3D&) = default;

      Mesh3D(int numberOfElementsInX, 
             int numberOfElementsInY, 
             int numberOfElementsInZ, 
             PolynomialOrder order = PolynomialOrder::Linear);

      int getNumberOfElements()    const;
      int getNumberOfElementsInX() const;
      int getNumberOfElementsInY() const;
      int getNumberOfElementsInZ() const;
      PolynomialOrder getOrder()   const;


      std::vector<Node3D*> getNodesThatSatisfies( std::function<bool(const Node3D& n)> which);
      
      void generateNodes();
      void createconnectivity();

      const std::vector<Node3D>& getNodes() const;
      const std::vector<Brick>&  getElements() const;

      const Node3D& getNode(int id) const;

    private:
      int  getNodeID(int i, int j, int k);



      int m_nxel = 0; 
      int m_nyel = 0; 
      int m_nzel = 0;

      int m_nnx  = 0; 
      int m_nny  = 0; 
      int m_nnz  = 0;
      PolynomialOrder m_order = PolynomialOrder::Linear;
      std::vector<Node3D> m_nodes;
      std::vector<Brick>  m_elements;
  };

}

#endif



