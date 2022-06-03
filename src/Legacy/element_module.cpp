#include "Legacy/element_module.h"


namespace LEGACY 
{

  void element_module::discretization_data() 
  {
    nxel      = 20;
    nyel      = 20; 
    nzel      = 20; 
    nntol     = nnx * nny * nnz;

    nnx       = (nbf_1d - 1) * nxel + 1;
    nny       = (nbf_1d - 1) * nyel + 1;
    nnz       = (nbf_1d - 1) * nzel + 1;

    nodtol    = nnx*nny*nnz;
    nunknowns = nodtol;



// NUNKNOWNS = NODTOL     
  }



}
