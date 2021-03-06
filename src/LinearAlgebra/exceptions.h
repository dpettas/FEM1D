#ifndef _FEM_LINEAR_ALGEBRA_EXCEPTION_INCLUDED_
#define _FEM_LINEAR_ALGEBRA_EXCEPTION_INCLUDED_

#include <exception>
#include <sstream>
#include <string>

namespace FEM 
{

  class ILinAlgExcecption: public std::exception 
  {
    public: 
      const char* what() const noexcept final 
      {
        return msg.c_str();
      }

    protected:
      std::string msg;

  };



  class NotEqualBalancedArrays : public ILinAlgExcecption 
  {
    public: 
      NotEqualBalancedArrays() = delete;
      NotEqualBalancedArrays(const std::string& whichFunction)
      {
        msg = whichFunction; 
        msg+= " ";
        msg+= "The arrays left and right of the assignment are not balanced.";
      }
  };

  class DublicatedIndex : public ILinAlgExcecption 
  {
    public: 
      DublicatedIndex() = delete;
      DublicatedIndex(const std::string& whichFunction)
      {
        msg = whichFunction; 
        msg+= " ";
        msg+= "One or more indices are dublicated in the Array";
      }
  };





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
     std::string msg;
  };


  class NotSameNumberOfColumns : public std::exception 
  {
    public: 
      NotSameNumberOfColumns() = default;
      NotSameNumberOfColumns(const std::string& whichFunction);

      const char* what() const noexcept override;
    private:
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

class LapackNotSameRank : public std::exception 
{
  public: 
    LapackNotSameRank() = default;
    LapackNotSameRank(const std::string& whichFunction, int mat_i, int mat_j, int b_i); 
    const char* what() const noexcept override;

  private:
    std::string msg;
};







}

#endif
