#include "AsciiTecplot.h"

namespace FEM 
{
  namespace IO 
  {
    AsciiTecplot::AsciiTecplot(const char* filename)
    {
      m_filename = filename;
    }

    

    void AsciiTecplot::open()
    {
      file.open(m_filename);
    }

    void AsciiTecplot::close()
    {
      file.close();
    }

  }
}




      //  WRITE(14,*)' TITLE = "FLOW"'
      //  WRITE(14,*)' VARIABLES = "X", "Y", "Z", "V" '
      //
      //
      //  WRITE(14,'(a,i10.10,a,i10.10,a)')&
      //  'ZONE T="3D ZONE", DATAPACKING=POINT, N= ', NUNKNOWNS, ', E= ', NNTOL, ', ZONETYPE= FEBRICK'
      //
      // WRITE(14,*)
      //
      //
      // DO I = 1, NUNKNOWNS
      // WRITE(14,'(4(1X,D14.6))') X(I), Y(I), Z(I), SOLUTION(I)
      // ENDDO
      //
      //
      // WRITE(14,*)
      // DO J = 1, NNTOL
      // WRITE(14,'(8(1X,I8))')(NMGR_ELEM(J,I),I=1,NBF_3d)
      // ENDDO
      //
      // CLOSE( 14, status='KEEP' )

