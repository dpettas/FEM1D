#include "LinearAlgebra/Array.h"
#include <utility>

#include <chrono>

// the work...


auto time_now = [](){return std::chrono::high_resolution_clock::now();};
int main (int argc, char *argv[])
{
  // auto t_start = time_now();
  // FEM::Array v = {1.0,2.0,3.0,4.0};;
  // auto t_end   = time_now();
  //
  // 
  // double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end-t_start).count();
  // std::cout << elapsed_time_ms << std::endl;

  FEM::Array v = {1.0,2.0,3.0,4.0};


  for(int i = 0; i < v.size(); ++i)
  {
    std::cout << v.get(i) << std::endl;
  }

  return 0;
}
