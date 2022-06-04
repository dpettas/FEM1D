#ifndef _FEM_LINEARLAGRANGE3D_INCLUDED_
#define _FEM_LINEARLAGRANGE3D_INCLUDED_ 

#include "BasisFunctions/LinearLagrange1D.h"

namespace FEM 
{

  class LinearLagrange3DBFunction 
  {
    public: 
      
      void set_diff_tolerance(double eps);

      LinearLagrange3DBFunction();
     ~LinearLagrange3DBFunction();

      LinearLagrange3DBFunction( const            LinearLagrange3DBFunction&  ) = delete;
      LinearLagrange3DBFunction(                  LinearLagrange3DBFunction&& ) = delete;
      LinearLagrange3DBFunction& operator= (const LinearLagrange3DBFunction&  ) = delete;
      LinearLagrange3DBFunction& operator= (      LinearLagrange3DBFunction&& ) = delete;

      int size() const;
      BFunction3D& phi(int i);

    
    private:
      int nbf = 8;
      BFunction3D* _phi = nullptr; 

  };



}



#endif
