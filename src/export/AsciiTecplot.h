#ifndef _FEM_ASCIITECPLOT_INCLUDED_
#define _FEM_ASCIITECPLOT_INCLUDED_
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <utility>

namespace FEM 
{
  namespace IO 
  {

    class AsciiTecplot
    {
      public: 
        using FieldValue = std::pair<std::string, std::vector<double>>;

        AsciiTecplot(const char* filename);
      
        void setName  (const char*);
        void setTitle (const char*);
        void setNumberOfPoints (int npoints);
        void setNumberOfElemets(int nelements);

        void open();
        void close();
        void write();
        const std::string& getName() const;
        const std::string& getTitle() const;
        std::string getFieldValuesNames();

        void addFieldValue(const std::string& name, const std::vector<double> val);
        void addConnectivity( const std::vector<std::vector<int>> elements);

        std::string   title_();
        std::string   variables_();
        std::string   header_();
        std::string   values_();

      private: 
        int m_npoints = 0; 
        int m_nelements = 0;

        std::string   m_filename    = "";
        std::string   m_title       = "FEMALE";
        std::string   m_zone        = "3D";
        std::string   m_datapacking = "POINT";
        std::string   m_zonetype    = "FEBRICK";
        std::ofstream m_file;
        std::vector<FieldValue> m_values;

    };

  }
}



#endif
