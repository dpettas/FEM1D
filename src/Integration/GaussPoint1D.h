#ifndef _FEM_GAUSSPOINT1D_INCLUDED_
#define _FEM_GAUSSPOINT1D_INCLUDED_ 

#include <iostream>
#include <utility>

namespace FEM 
{
  class GaussPoint1D
  {
    public: 
      GaussPoint1D(double m_position, double m_weight);
      GaussPoint1D(const GaussPoint1D& other) = default;


      std::pair<double,double> get() const;


    private:
      double m_position = 0.0;
      double m_weight   = 0.0;

  };
}


#endif
