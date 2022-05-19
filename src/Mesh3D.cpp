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
  
  const Node3D& Mesh3D::getNode(int id) const
  {
    return m_nodes[id];
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
  
  std::vector<Node3D*> Mesh3D::getNodesThatSatisfies( std::function<bool(const Node3D& n)> which)
  {
    std::vector<Node3D*> out;

    for (Node3D& node : m_nodes)
    {
      if (which(node)) out.push_back(&node);
    }

    return out;
  }





  void Mesh3D::createconnectivity()
  {

    elements.resize(this->getNumberOfElements());
    int nelem = -1;

    for (int i = 0; i < m_nzel; ++i)
    {
      for (int j = 0; j < m_nyel; ++j)
      {
        for (int k = 0; k < m_nxel; ++k)
        {
          // Only for Linear
          // std::cout << k << std::endl;
          int NBF_1d = static_cast<int>(PolynomialOrder::Linear);
          int jj     = (NBF_1d-1)*(k-0) + 0;
          int surf   = i -0;
          int level  = j -0;
          int mnd    = m_nnx * m_nny;
          int nnd    = m_nnx;


          std::vector<int> element;
          element.resize(8);

          element[0] = surf * mnd + level * nnd + jj;
          element[1] = element[0] + 1;
          element[3] = surf * mnd + (level + 1) * nnd + jj;
          element[2] = element[3] + 1;
          element[4] = (surf + 1) * mnd + (level) * nnd + jj;
          element[5] = element[4] + 1;
          element[7] = (surf + 1) * mnd + (level+1) * nnd + jj;
          element[6] = element[7] + 1;

          ++nelem; 
          for(auto id : element)
            std::cout << id+1 << " ";
          std::cout << std::endl;


        }
        // std::cout << std::endl;
      }
    }


		  
		 		 



  }

}
