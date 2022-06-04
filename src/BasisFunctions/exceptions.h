#ifndef _FEM_BASISFUNCTIONS_EXCEPTIONS_INCLUDED_
#define _FEM_BASISFUNCTIONS_EXCEPTIONS_INCLUDED_ 

#include <exception>
#include <sstream>
#include <string>

namespace FEM
{
  class NotGerericImplementation : public std::exception 
  {
    public: 
      NotGerericImplementation() = default; 
      NotGerericImplementation(const std::string& msg)
      {
        _msg = msg;
      }

      const char* what() const noexcept override
      {
        return _msg.c_str();
      }

    private: 
      std::string _msg;

  };


  class OutOfBoundsIndex : public std::exception 
  {
    public: 
      OutOfBoundsIndex() = delete;
      OutOfBoundsIndex(const std::string& msg, int i, int min, int max)
      {
        std::stringstream out; 


        out << msg; 
        out << " ";
        out << "The index i : " << i << "is out of bounds";
        out << "possible values are in the range ["<<min<<","<<max<<"]\n";

        _msg = out.str();
      }

      const char* what() const noexcept override
      {
        return _msg.c_str();
      }

    private: 
      std::string _msg;

  };

}



#endif
