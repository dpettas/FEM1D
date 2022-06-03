
namespace LEGACY 
{

  struct element_module
  {
    int nbf_1d = 2;
    int nbf_2d = nbf_1d * nbf_1d;
    int nbf_3d = nbf_2d * nbf_1d;

    int nxel; 
    int nyel;
    int nzel; 
    int nntol;

    int nnx;
    int nny;
    int nnz;

    int nodtol;
    int nunknowns;

    void discretization_data();
  };




}
