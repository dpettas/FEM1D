#ifndef _FEM_DENSEMATRIX_INCLUDED_
#define _FEM_DENSEMATRIX_INCLUDED_

#include <exception>
#include <sstream>
#include <string>

namespace FEM 
{

  class NotEqualSizedArrays: public std::exception
  {
    public:
      NotEqualSizedArrays() = default;
      NotEqualSizedArrays (const std::string& whichFunction);
     const char * what() const noexcept override;

    private: 
     std::string m_whichFunction;
     std::string msg;
  };


  class OutOfBoundsIndex: public std::exception
  {
    public:
      OutOfBoundsIndex() = default;
      OutOfBoundsIndex (const std::string& whichFunction, int i);
     const char * what() const noexcept override;

    private: 
     std::string m_whichFunction;
     std::string msg;
  };









}

#endif
