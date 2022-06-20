#ifndef _FEM_EXCEPTIONS_INCLUDED_
#define _FEM_EXCEPTIONS_INCLUDED_ 

#include <exception>
#include <string>

namespace FEM 
{
  class NotImplementedError : public std::exception
  {
    public:
      NotImplementedError() = default; 

      const char* what() const noexcept override
      {
       return _func.c_str();
      }
    private: 
      std::string _func;

    
  };
  



  
}




#endif
