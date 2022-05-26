#include "LinearAlgebra/Array.h"
#include <utility>

#include <chrono>

// the work...


auto time_now = [](){return std::chrono::high_resolution_clock::now();};
int main (int argc, char *argv[])
{
  auto t_start = time_now();
  FEM::Array v(FEM::Array(1000000, 0.0));
  auto t_end   = time_now();

  
  double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end-t_start).count();
  std::cout << elapsed_time_ms << std::endl;
  return 0;
}
