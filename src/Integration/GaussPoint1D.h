#ifndef _FEM_GAUSSPOINT1D_INCLUDED_
#define _FEM_GAUSSPOINT1D_INCLUDED_ 

#include <iostream>
#include <utility>
#include "IGaussPoint.h"

namespace FEM 
{
  class GaussPoint1D  : public IGaussPoint
  {
    public: 
      
      GaussPoint1D() = default;
      GaussPoint1D(double position1, double weight);
      GaussPoint1D(const GaussPoint1D&  other);
      GaussPoint1D(      GaussPoint1D&& other);

      GaussPoint1D& operator=(const GaussPoint1D&  that);
      GaussPoint1D& operator=(      GaussPoint1D&& that);

      int      size()     const noexcept override { return 1;}
      double*  position() const noexcept override { return m_position;}
      double   weight()   const noexcept override { return m_weight;}


    private:
      double* m_position = nullptr;
      double m_weight   = 0.0;

  };
}


#endif
