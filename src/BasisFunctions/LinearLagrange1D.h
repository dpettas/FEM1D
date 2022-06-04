#ifndef _FEM_LINEARLAGRANGE1D_INCLUDED_
#define _FEM_LINEARLAGRANGE1D_INCLUDED_ 

#include "BasisFunctions/BasisFunction.h"
// Linear Basis Functions defined in the range of [-1,1]
//

namespace FEM 
{

  class LinearLagrange1DBFunction 
  {
    public: 
      
      void set_diff_tolerance(double eps);

      LinearLagrange1DBFunction();
     ~LinearLagrange1DBFunction();

      LinearLagrange1DBFunction( const            LinearLagrange1DBFunction&  ) = delete;
      LinearLagrange1DBFunction(                  LinearLagrange1DBFunction&& ) = delete;
      LinearLagrange1DBFunction& operator= (const LinearLagrange1DBFunction&  ) = delete;
      LinearLagrange1DBFunction& operator= (      LinearLagrange1DBFunction&& ) = delete;

      int size() const;
      BFunction1D& phi(int i);

    
    private:
      int nbf = 2;
      BFunction1D* _phi = nullptr; 

  };



}


#endif
