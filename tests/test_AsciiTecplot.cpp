#include <iostream>
#include <vector>
#include "export/AsciiTecplot.h"
#include "Mesh3D.h"
#include "Elements/Brick.h"


std::vector<double> flattenX(const FEM::Mesh3D&);
std::vector<double> flattenY(const FEM::Mesh3D&);
std::vector<double> flattenZ(const FEM::Mesh3D&);

template<typename T>
void printVec(std::vector<T> obj, const char* sep = " "){
  for (T& v : obj)
  {
    std::cout << v << sep;
  }
}

int main (int argc, char *argv[])
{
  FEM::Mesh3D mesh(10,5,3, FEM::Mesh3D::PolynomialOrder::Linear);
  mesh.generateNodes();
  mesh.createconnectivity();

  const std::vector<FEM::Brick>& elements = mesh.getElements(); 
  
 
  for(const FEM::Brick& element : elements)
  {
    printVec(element.getNodeLabels());
    std::cout << std::endl;
  
  }





  std::exit(0);
  std::vector<double> x = flattenX(mesh);
  std::vector<double> y = flattenY(mesh);
  std::vector<double> z = flattenZ(mesh);

  FEM::IO::AsciiTecplot tecfile ("test.plt");
  tecfile.open();
  tecfile.setNumberOfPoints (x.size());
  tecfile.setNumberOfElemets(mesh.getNumberOfElements());
  //
  tecfile.addFieldValue("X",x);
  tecfile.addFieldValue("Y",y);
  tecfile.addFieldValue("Z",z);

// Ordere of Connectivity (Linear)
// 1 2 4 3 5 6 8 7

  tecfile.write();
  tecfile.close();
  return 0;
}

std::vector<double> flattenX(const FEM::Mesh3D& mesh)
{
  std::vector<double> out;

  const std::vector<FEM::Node3D>& nodes = mesh.getNodes();

  for (const FEM::Node3D& node : nodes)
  {
    out.push_back(node.getX());
  }

  return out;
}

std::vector<double> flattenY(const FEM::Mesh3D& mesh)
{
  std::vector<double> out;

  const std::vector<FEM::Node3D>& nodes = mesh.getNodes();

  for (const FEM::Node3D& node : nodes)
  {
    out.push_back(node.getY());
  }

  return out;
}

std::vector<double> flattenZ(const FEM::Mesh3D& mesh)
{
  std::vector<double> out;

  const std::vector<FEM::Node3D>& nodes = mesh.getNodes();

  for (const FEM::Node3D& node : nodes)
  {
    out.push_back(node.getZ());
  }

  return out;
}
