#include <iostream>
#include "export/AsciiTecplot.h"



int main (int argc, char *argv[])
{
  FEM::IO::AsciiTecplot tecfile ("test.plt");
  tecfile.open();


  tecfile.close();
  return 0;
}
