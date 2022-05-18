#include <iostream>
#include <vector>
#include "export/AsciiTecplot.h"



int main (int argc, char *argv[])
{
  FEM::IO::AsciiTecplot tecfile ("test.plt");
  tecfile.open();

  std::vector<double> x {0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0};
  std::vector<double> y {0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0};
  std::vector<double> z {0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0};

  tecfile.setNumberOfPoints (8);
  tecfile.setNumberOfElemets(1);

  tecfile.addFieldValue("X",x);
  tecfile.addFieldValue("Y",y);
  tecfile.addFieldValue("Z",z);

// Ordere of Connectivity (Linear)
// 1 2 4 3 5 6 8 7

  tecfile.write();
  tecfile.close();
  return 0;
}
