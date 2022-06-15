#include "Integration/GPointCollections.h"
#include <assert.h>


int main (int argc, char *argv[])
{

  assert( FEM::COLLECTIONS::GPoints27_3D [0].weight() == (5.0/9.0)*(5.0/9.0)*(5.0/9.0)  );

  
  return 0;
}
