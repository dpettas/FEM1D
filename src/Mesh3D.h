// #ifndef _FEM_MESH3D_INCLUDED_
// #define _FEM_MESH3D_INCLUDED_ 
//
// #include "Node/Node.h"
// #include "Elements/Brick.h"
// #include "export/AsciiTecplot.h"
// #include <algorithm>
// #include <vector>
// #include <iostream>
// #include <iomanip>
// #include <functional>
//
// namespace FEM
// {
//   class Mesh3D
//   {
//     public:
//
//       Mesh3D() = default;
//       Mesh3D(const Mesh3D&) = default;
//
//       Mesh3D(int numberOfElementsInX,
//              int numberOfElementsInY,
//              int numberOfElementsInZ);
//
//       int getNumberOfNodes()       const;
//       int getNumberOfElements()    const;
//       int getNumberOfElementsInX() const;
//       int getNumberOfElementsInY() const;
//       int getNumberOfElementsInZ() const;
//
//       std::vector<Node3D*> getNodesThatSatisfies( std::function<bool(const Node3D& n)> which);
//     
//
//       const std::vector<Node3D>& getNodes() const;
//       const std::vector<Brick>&  getElements() const;
//
//       const Node3D& getNode(int id) const;
//       const Brick&  getElement(int id) const;
//
//       void toAsciiTeplot(const std::string& filename);
//
//     private:
//       int  getNodeID(int i, int j, int k);
//       void generateNodes();
//       void createconnectivity();
//
//
//
//       int m_nxel = 0;
//       int m_nyel = 0;
//       int m_nzel = 0;
//
//       int m_nnx  = 0;
//       int m_nny  = 0;
//       int m_nnz  = 0;
//       std::vector<Node3D> m_nodes;
//       std::vector<Brick>  m_elements;
//   };
//
// }
//
// #endif
//
//
//
