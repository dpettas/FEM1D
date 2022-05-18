#ifndef _FEM_ASCIITECPLOT_INCLUDED_
#define _FEM_ASCIITECPLOT_INCLUDED_
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

namespace FEM 
{
  namespace IO 
  {

    class AsciiTecplot
    {
      public: 
        AsciiTecplot(const char* filename);
       
        void setTitle(const char*);
        void addColumn(const char* col, std::vector<double> val);

        void open();
        void close();
        const char* getName() const;

      private: 
        std::string m_filename;
        std::ofstream file;


    };

  }
}



#endif
