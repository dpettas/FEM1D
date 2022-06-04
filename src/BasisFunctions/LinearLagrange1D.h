#ifndef _FEM_LINEARLAGRANGE1D_INCLUDED_
#define _FEM_LINEARLAGRANGE1D_INCLUDED_ 

#include "BasisFunctions/BasisFunction.h"
// Linear Basis Functions defined in the range of [-1,1]
//

namespace FEM 
{

  class LinearLagrangeBFunction 
  {
    public: 
      
      void set_diff_tolerance(double eps);

      LinearLagrangeBFunction();
     ~LinearLagrangeBFunction();

      LinearLagrangeBFunction( const            LinearLagrangeBFunction&  ) = delete;
      LinearLagrangeBFunction(                  LinearLagrangeBFunction&& ) = delete;
      LinearLagrangeBFunction& operator= (const LinearLagrangeBFunction&  ) = delete;
      LinearLagrangeBFunction& operator= (      LinearLagrangeBFunction&& ) = delete;

      int size() const;
      BFunction1D& phi(int i);

    
    private:
      int nbf = 2;
      BFunction1D* _phi = nullptr; 

  };



}


#endif
