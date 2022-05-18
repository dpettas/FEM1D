#include "Mesh3D.h"


namespace FEM
{
  Mesh3D::Mesh3D(int numberOfElementsInX, 
                 int numberOfElementsInY, 
                 int numberOfElementsInZ, 
                 PolynomialOrder order):
    m_nxel(numberOfElementsInX),
    m_nyel(numberOfElementsInY),
    m_nzel(numberOfElementsInZ),
    m_order(order)
  {
    m_nnx = (static_cast<int>(order) - 1) * m_nxel + 1;
    m_nny = (static_cast<int>(order) - 1) * m_nyel + 1;
    m_nnz = (static_cast<int>(order) - 1) * m_nzel + 1;
  }


  int Mesh3D::getNumberOfElements() const
  {
    return m_nxel * m_nyel * m_nzel;
  }

  int Mesh3D::getNumberOfElementsInX() const 
  {
    return m_nxel;
  }

  int Mesh3D::getNumberOfElementsInY() const 
  {
    return m_nyel;
  }

  int Mesh3D::getNumberOfElementsInZ() const 
  {
    return m_nzel;
  }

  int Mesh3D::getNodeID(int i, int j, int k)
  {
    return k * m_nnx*m_nny + j * m_nnx + i;
  }

 
  Mesh3D::PolynomialOrder Mesh3D::getOrder() const
  {
    return m_order;
  }

  const std::vector<Node3D>& Mesh3D::getNodes() const
  {
    return m_nodes;
  }


  void Mesh3D::generateNodes()
  {

    double dorder = static_cast<double>(m_order) - 1.0;


    for (int i = 0; i < m_nnx; ++i)
    {
      for (int j = 0; j < m_nny; ++j)
      {
        for (int k = 0; k < m_nnz; ++k)
        {
          int nodeid  = this->getNodeID(i,j,k);
          double x = (static_cast<double>(i))/(m_nxel);
          double y = (static_cast<double>(j))/(m_nyel);
          double z = (static_cast<double>(k))/(m_nzel);

          x /= dorder;
          y /= dorder;
          z /= dorder;
          
          Node3D node {nodeid, x, y, z};
          m_nodes.push_back(node);
        }
      }
    }



    auto sort_byLabel = [](const Node3D& node1, const Node3D& node2){
      return node1.getLabel() < node2.getLabel();
    };


    std::sort(m_nodes.begin(), m_nodes.end(), sort_byLabel);
  }
  
  void Mesh3D::createconnectivity()
  {

  }

}
