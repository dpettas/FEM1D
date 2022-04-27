#include "Mesh1D.h"
#include <fstream>

#include <iostream>


int main (int argc, char *argv[])
{

  FEM::Mesh1D d0(-1.0, 1.0, 10);


  FEM::Mesh1D::IDENTITY(d0.getNumNodes(), d0.getNodes());
  // d0.setSpaceModifier(FEM::Mesh1D::IDENTITY);

  std::ofstream out;
  out.open("nodes.dat");

  std::cout << d0.getLowBound()   << std::endl;
  std::cout << d0.getUpperBound() << std::endl;
  std::cout << d0.getNumNodes()   << std::endl;

  for (int i = 0; i < d0.getNumNodes(); ++i){
    double x = *d0.getNodes()[i].getPoint()->getCoordinates();
    out << x << " " << 0.0 << std::endl;
  }
  
  return 0;
}
