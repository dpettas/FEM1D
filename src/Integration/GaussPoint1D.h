#ifndef _FEM_GAUSSPOINT1D_INCLUDED_
#define _FEM_GAUSSPOINT1D_INCLUDED_ 

#include <iostream>

class GaussPoint1D
{
  public: 
    GaussPoint1D() = default;


  private:
    double position = 0.0;
    double weight   = 0.0;

};


#endif
