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
      m_file.open(m_filename);
    }

    void AsciiTecplot::close()
    {
      m_file.close();
    }

    void AsciiTecplot::write()
    {
      if(!m_file.is_open()) m_file.open(m_filename);
      m_file << this->title_() << std::endl;
      m_file << this->variables_() << std::endl;
      m_file << this->header_() << std::endl;
      m_file << this->values_() << std::endl;

    }


    void AsciiTecplot::addFieldValue(const std::string& name, const std::vector<double> val)
    {
      m_values.push_back({name, val});
    }

    std::string AsciiTecplot::getFieldValuesNames()
    {
      std::string out = "";
      for(FieldValue fv : m_values)
        out += fv.first + ',';

      out.pop_back();

      return out;
    }


    void AsciiTecplot::setName(const char* filename)
    {
      m_filename = filename;
    }

    void AsciiTecplot::setTitle(const char* title)
    {
      m_title = title;
    }


    const std::string& AsciiTecplot::getName() const
    {
      return m_filename;
    }


    const std::string& AsciiTecplot::getTitle() const
    {
      return m_title;
    }

    void AsciiTecplot::setNumberOfPoints(int npoints)
    {
      m_npoints = npoints;
    }

 
    void AsciiTecplot::setNumberOfElemets(int nelements)
    {
      m_nelements = nelements;
    }
    
    std::string AsciiTecplot::title_()
    {
      std::stringstream out;
      out << "TITLE = ";
      out << "\"";
      out << m_title;
      out << "\"";

      return out.str();
    }

    std::string AsciiTecplot::variables_() 
    {
      std::stringstream out;
      out << "VARIABLES = ";
      for (const FieldValue& fv : m_values)
      {
        out << "\"";
        out << fv.first;
        out << "\"";
        out << " ,";
      }
      std::string out_ = out.str(); 
      out_.pop_back();

      return out_;
    }

    std::string AsciiTecplot::header_()
    {
      std::stringstream out; 
      out << "ZONE T = ";
      out << "\"";
      out << m_zone; 
      out << "\"";
      out << ", ";
      out << "DATAPACKING = ";
      out << m_datapacking; 
      out << ", ";
      out << "N = ";
      out << std::to_string(m_npoints);
      out << ", ";
      out << "E = ";
      out << std::to_string(m_nelements);
      out << ", ";
      out << "ZONETYPE = ";
      out << m_zonetype;


      return out.str();
    }

    std::string AsciiTecplot::values_() 
    {
      std::stringstream out; 

      out << std::setprecision(8);
      out << std::scientific;
      out << std::endl;

      for(int i = 0; i < m_npoints; ++i)
      {
        for (int j = 0; j < m_values.size(); ++j)
        {
          out << m_values.at(j).second[i] << "  ";

        }
        out << '\n';
      }


      return out.str();
    }

  



  }
}




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

