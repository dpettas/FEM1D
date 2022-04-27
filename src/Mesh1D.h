#ifndef _FEM1D_MESH1D_INCLUDED_
#define _FEM1D_MESH1D_INCLUDED_

namespace FEM{



  class Mesh1D{

    public:

      class Transformation{
        public:

        private:

      };


      Mesh1D();
      Mesh1D(double low_, double max_, int num_nodes_);
      Mesh1D(const Mesh1D& rhs);
      ~Mesh1D();


    private:
      int     num_nodes;
      double  xlow;
      double  xmax;
      double* x;



  };


}



#endif
