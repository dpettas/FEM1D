#include "LinearAlgebra/Array.h"
#include <utility>

#include <chrono>
#include <cstdlib>

// the work...


auto time_now = [](){return std::chrono::high_resolution_clock::now();};
int main (int argc, char *argv[])
{

  FEM::Array a = {1,2,3};
  FEM::Array b = {1,2,3}; 


  FEM::Array c = a + b;

  for(int i = 0; i < c.size(); ++i)
  {
    std::cout << c.get(i) << std::endl;
  }

  std::cout << "End\n";

  // auto t_start = time_now();
  // FEM::Array v = {1.0,2.0,3.0,4.0};;
  // auto t_end   = time_now();
  //
  // 
  // double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end-t_start).count();
  // std::cout << elapsed_time_ms << std::endl;

  // FEM::Array v = {1.0,2.0,3.0,4.0};

  // FEM::Array vv;
  // vv = {1.0, 2,3,4,5};
  //
  // FEM::Array vvv = {1.0};
  //
  // vvv = {1,2,3,4,5};
  //
  // for(const auto it : vv){
  //   std::cout << it << std::endl;
  // }

  // for(int i = 0; i < v.size(); ++i)
  // {
  //   std::cout << v.get(i) << std::endl;
  // }

  return 0;
}
