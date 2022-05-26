#include "LinearAlgebra/Array.h"
#include <utility>


int main (int argc, char *argv[])
{
  FEM::Array v = std::move(FEM::Array(10, 0.0) );

  
  return 0;
}
