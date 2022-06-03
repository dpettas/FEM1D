#include <iostream>
#include <BasisFunctions/Function.h>

int main (int argc, char *argv[])
{
  auto phi =  FEM::BasisFunction( [](double ksi, double eta, double zeta) {return ksi;} );
  auto fn = phi.function();
  auto dksi = phi.dksi(2);

  std::cout << fn(4.0,1,1) << std::endl;
  std::cout << dksi << std::endl;

  
  return 0;
}
