#ifndef _FEM_FUNCTION_INCLUDED_
#define _FEM_FUNCTION_INCLUDED_ 

#include <functional>

namespace FEM 
{

  class BasisFunction
  {
    public: 

      static double eps; 
      static void set_tolerance(double _eps) { eps = _eps; }

      BasisFunction() = delete;
      explicit BasisFunction(std::function<double(double)> fn_1);
      explicit BasisFunction(std::function<double(double, double)> fn_2);
      explicit BasisFunction(std::function<double(double, double, double)> fn_3);


    private:

      std::function<double(double,double,double)> fn;
      

  };

}






#endif
