#ifndef _FEM1D_MESH1D_INCLUDED_
#define _FEM1D_MESH1D_INCLUDED_

namespace FEM{


  class SpartialModifier{
    public:

    private:

  };
// use uniform 


  class Mesh1D{

    public:

      Mesh1D(double xlow_, double xmax_);
      Mesh1D(double xlow_, double xmax_, SpartialModifier sp);
      Mesh1D(const Mesh1D& rhs);

    private:


  };


}



#endif
