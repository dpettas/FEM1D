#include <iostream>
#include "Point1D.h"


int main(){

  double a = 1.0;
  double* x = &a;

  std::cout << x[0] << std::endl;

  return 0;
}
