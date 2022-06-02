#ifndef _FEM_ARRAY_INCLUDED_
#define _FEM_ARRAY_INCLUDED_

#include <iostream> 
#include <initializer_list>
#include <numeric>
#include <cmath>
#include <tuple>
#include <vector>
#include "exceptions.h"



namespace FEM 
{





  class Array 
  {
    private: 

      class Indices 
      {
        public: 
          Indices(std::initializer_list<int> il) 
          {
            m_size = il.size();
            m_val  = new int [m_size];

            int i = 0;
            for (int val : il)
            {
              m_val[i] = val;
              ++i;
            }
          }

          int size() const  {return m_size;}
          int get(int idx) const {return m_val[idx];}
          int* begin() const {return m_val;}
          int* end() const {return (m_val + m_size);}

          ~Indices()
          {
            delete [] m_val;
          }

        private: 
          int  m_size = 0; 
          int* m_val  = nullptr;
      };

      class Values 
      {
        public: 
          Values() = default;
          Values(const Array& init) = delete;

          Values operator = (const Array& arr)
          {
            if (arr.size() != (int) m_values.size() )
              throw "The array of the right has not the same length with the array of the left";

            for (int i = 0; i < (int) m_values.size(); ++i)
            {
              *m_values[i] = arr.get(i);
            }

            return *this;
          }

          void add(double& val) {return m_values.push_back(&val);}
          double* get(int i) const {return m_values.at(i);}
        private:
          std::vector<double*> m_values;


      };



      int m_size = 0;
      double* m_values = nullptr;
    public: 





      Array() = default;
      Array(int size, double init = 0.0);
      Array(std::initializer_list<double> il);
      Array(const Array& other);
      Array( Array&& other);
      ~Array();

      Array& operator = (const Array& that);
      Array& operator = ( Array&& that);

      int size() const;
      double& get(int i) noexcept;
      double  get(int i) const noexcept;

      double* begin()  { return  m_values;}
      double* end()    { return (m_values + m_size);}



      Array  operator+ (const Array& other);
      Array& operator+=(const Array& other);
      Array  operator- (const Array& other);
      Array& operator-=(const Array& other);

      double&  operator() (int i);
      Values   operator() (const Indices& idx);
      
      
      double   at(int i) const;

      double L2norm();
      

  };


}


#endif
