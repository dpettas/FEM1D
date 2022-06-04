#include "math/functions.h"
#include <algorithm>

namespace FEM 
{

  std::vector<double> linspace(double low, double upper, int num)
  {
    std::vector<double> out(num); 


    for (int i = 0; i < num; ++i)
      out[i] = low + static_cast<double> (i)/(num-1) * (upper - low);

    return out;
  }

}



