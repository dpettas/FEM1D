// #include "Mesh3D.h"
//
//
// namespace FEM
// {
//   Mesh3D::Mesh3D(int numberOfElementsInX,
//                  int numberOfElementsInY,
//                  int numberOfElementsInZ):
//     m_nxel(numberOfElementsInX),
//     m_nyel(numberOfElementsInY),
//     m_nzel(numberOfElementsInZ)
//   {
//     int nbf = 2;
//     m_nnx = (nbf - 1) * m_nxel + 1;
//     m_nny = (nbf - 1) * m_nyel + 1;
//     m_nnz = (nbf - 1) * m_nzel + 1;
//
//     this->generateNodes();
//     this->createconnectivity();
//   }
//
//
//   int Mesh3D::getNumberOfElements() const
//   {
//     return m_nxel * m_nyel * m_nzel;
//   }
//
//   int Mesh3D::getNumberOfNodes() const
//   {
//     return m_nodes.size();
//   }
//
//   int Mesh3D::getNumberOfElementsInX() const
//   {
//     return m_nxel;
//   }
//
//   int Mesh3D::getNumberOfElementsInY() const
//   {
//     return m_nyel;
//   }
//
//   int Mesh3D::getNumberOfElementsInZ() const
//   {
//     return m_nzel;
//   }
//
//   int Mesh3D::getNodeID(int i, int j, int k)
//   {
//     return k * m_nnx*m_nny + j * m_nnx + i;
//   }
//  
//   const Node3D& Mesh3D::getNode(int id) const
//   {
//     return m_nodes[id];
//   }
//  
//   const Brick& Mesh3D::getElement(int id) const
//   {
//     return m_elements[id];
//   }
//
//
//
//   const std::vector<Node3D>& Mesh3D::getNodes() const
//   {
//     return m_nodes;
//   }
//
//
//   const std::vector<Brick>&  Mesh3D::getElements() const
//   {
//     return m_elements;
//   }
//
//   void Mesh3D::generateNodes()
//   {
//
//     int nbf = 2;
//     double dorder = nbf - 1.0;
//
//
//     for (int i = 0; i < m_nnx; ++i)
//     {
//       for (int j = 0; j < m_nny; ++j)
//       {
//         for (int k = 0; k < m_nnz; ++k)
//         {
//           int nodeid  = this->getNodeID(i,j,k);
//           double x = (static_cast<double>(i))/(m_nxel);
//           double y = (static_cast<double>(j))/(m_nyel);
//           double z = (static_cast<double>(k))/(m_nzel);
//
//           x /= dorder;
//           y /= dorder;
//           z /= dorder;
//          
//           Node3D node {nodeid, x, y, z};
//           m_nodes.push_back(node);
//         }
//       }
//     }
//
//
//
//     auto sort_byLabel = [](const Node3D& node1, const Node3D& node2){
//       return node1.getLabel() < node2.getLabel();
//     };
//
//
//     std::sort(m_nodes.begin(), m_nodes.end(), sort_byLabel);
//   }
//  
//   std::vector<Node3D*> Mesh3D::getNodesThatSatisfies( std::function<bool(const Node3D& n)> which)
//   {
//     std::vector<Node3D*> out;
//
//     for (Node3D& node : m_nodes)
//     {
//       if (which(node)) out.push_back(&node);
//     }
//
//     return out;
//   }
//
//
//   void Mesh3D::toAsciiTeplot(const std::string& filename)
//   {
//   
//     auto flattenX = [this]()
//     {
//       std::vector<double> out;
//       auto& nodes = this->getNodes();
//       for(auto node : nodes) out.push_back(node.get()[0]);
//       return out;
//     };
//
//     auto flattenY = [this]()
//     {
//       std::vector<double> out;
//       auto& nodes = this->getNodes();
//       for(auto node : nodes) out.push_back(node.get()[1]);
//       return out;
//     };
//
//     auto flattenZ = [this]()
//     {
//       std::vector<double> out;
//       auto& nodes = this->getNodes();
//       for(auto node : nodes) out.push_back(node.get()[2]);
//       return out;
//     };
//
//     auto connectivity = [this]()
//     {
//       std::vector<std::vector<int>> out;
//       for (auto& element : this->getElements() )
//       {
//         out.push_back(element.getNodeLabels());
//       }
//       return out;
//     };
//  
//
//
//     IO::AsciiTecplot tecfile (filename.c_str());
//     tecfile.open();
//     tecfile.setNumberOfPoints(this->getNumberOfNodes());
//     tecfile.setNumberOfElemets(this->getNumberOfElements());
//     tecfile.addFieldValue("X",flattenX());
//     tecfile.addFieldValue("Y",flattenY());
//     tecfile.addFieldValue("Z",flattenZ());
//     tecfile.addConnectivity(connectivity());
//     tecfile.write();
//     tecfile.close();
//   }
//
//
//
//
//
//   void Mesh3D::createconnectivity()
//   {
//
//     for (int i = 0; i < m_nzel; ++i)
//     {
//       for (int j = 0; j < m_nyel; ++j)
//       {
//         for (int k = 0; k < m_nxel; ++k)
//         {
//           // Only for Linear
//           // std::cout << k << std::endl;
//           int NBF_1d = 2;
//           int jj     = (NBF_1d-1)*(k-0) + 0;
//           int surf   = i -0;
//           int level  = j -0;
//           int mnd    = m_nnx * m_nny;
//           int nnd    = m_nnx;
//
//
//           int element_id;
//           Brick  element;
//
//           auto node_id = [mnd, nnd](int surf_, int level_, int loc_)
//           {
//             return surf_ * mnd + level_ * nnd + loc_;
//           };
//
//           element_id  = node_id(surf + 0, level + 0, jj + 0);
//           element.addNode( this->getNode(element_id));
//
//           element_id  = node_id(surf + 0, level + 0, jj + 1);
//           element.addNode( this->getNode(element_id));
//          
//           element_id  = node_id(surf + 0, level + 1, jj + 1);
//           element.addNode( this->getNode(element_id));
//
//           element_id  = node_id(surf + 0, level + 1, jj + 0);
//           element.addNode( this->getNode(element_id));
//
//           element_id  = node_id(surf + 1, level + 0, jj + 0);
//           element.addNode( this->getNode(element_id));
//
//           element_id  = node_id(surf + 1, level + 0, jj + 1);
//           element.addNode( this->getNode(element_id));
//
//           element_id  = node_id(surf + 1, level + 1, jj + 1);
//           element.addNode( this->getNode(element_id));
//
//           element_id  = node_id(surf + 1, level + 1, jj + 0);
//           element.addNode( this->getNode(element_id));
//
//          
//           m_elements.push_back(element);
//         }
//       }
//     }
//   }
//
// }
