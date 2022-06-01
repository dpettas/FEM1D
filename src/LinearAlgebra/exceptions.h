#ifndef _FEM_LINEAR_ALGEBRA_EXCEPTION_INCLUDED_
#define _FEM_LINEAR_ALGEBRA_EXCEPTION_INCLUDED_

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

class LapackArgumentIllegalValue : public std::exception
{
  public: 
    LapackArgumentIllegalValue() = default; 
    LapackArgumentIllegalValue(const std::string& whichFunction, int i);
    const char* what() const noexcept override;

  private: 
    std::string m_whichFunction; 
    std::string msg;

};

class LapackZeroDiagonalValue : public std::exception 
{
  public: 
    LapackZeroDiagonalValue() = default;
    LapackZeroDiagonalValue(const std::string& whichFunction, int i);

    const char* what() const noexcept override;

  private:
    std::string msg;

};









}

#endif
