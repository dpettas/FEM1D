#include <iostream>
#include "Point1D.h"
#include "Node.h"

#include "Mesh3D.h"


int main(){


  FEM::Mesh3D mesh(5,5,5);

  mesh.toAsciiTeplot("fromMain.plt");


  std::cout << "End\n";
  return 0;
}
