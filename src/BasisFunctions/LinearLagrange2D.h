#ifndef _FEM_LINEARLAGRANGE2D_INCLUDED_
#define _FEM_LINEARLAGRANGE2D_INCLUDED_ 

#include "BasisFunctions/BasisFunction.h"
#include "BasisFunctions/LinearLagrange1D.h"

namespace FEM 
{

  class LinearLagrange2DBFunction 
  {
    public: 
      
      void set_diff_tolerance(double eps);

      LinearLagrange2DBFunction();
     ~LinearLagrange2DBFunction();

      LinearLagrange2DBFunction( const            LinearLagrange2DBFunction&  ) = delete;
      LinearLagrange2DBFunction(                  LinearLagrange2DBFunction&& ) = delete;
      LinearLagrange2DBFunction& operator= (const LinearLagrange2DBFunction&  ) = delete;
      LinearLagrange2DBFunction& operator= (      LinearLagrange2DBFunction&& ) = delete;

      int size() const;
      BFunction2D& phi(int i);

    
    private:
      int nbf = 4;
      BFunction2D* _phi = nullptr; 

  };



}




#endif
