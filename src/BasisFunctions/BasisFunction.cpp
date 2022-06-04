#include "BasisFunctions/BasisFunction.h"

namespace FEM 
{


template<>
  BFunction<double>::_func  
  BFunction<double>::derWithRespectTo(int i)
  {
    if (i >= dimensionality() || i < 0)
      throw FEM::OutOfBoundsIndex("BasisFunction::derWithRespectTo",i,0,0);

    _func& bf = _basisFunction;
    return [this,&bf](double x1) {return (bf(x1+_eps) - bf(x1))/_eps;};
  }
  

template<>
  BFunction<double,double>::_func  
  BFunction<double,double>::derWithRespectTo(int i)
  {
    if (i >= dimensionality() || i < 0)
      throw FEM::OutOfBoundsIndex("BasisFunction::derWithRespectTo",i,0,1);

    _func& bf = _basisFunction;

    if (i == 0)
      return [this,&bf](double x1, double x2) 
            {return (bf(x1+_eps,x2) - bf(x1,x2))/_eps;};
    
    if (i==1)
      return [this,&bf](double x1, double x2) 
            {return (bf(x1,x2 + _eps) - bf(x1,x2))/_eps;};

    throw 0;
  }

template<>
  BFunction<double,double,double>::_func  
  BFunction<double,double,double>::derWithRespectTo(int i)
  {
    if (i >= dimensionality() || i < 0)
      throw FEM::OutOfBoundsIndex("BasisFunction::derWithRespectTo",i,0,2);

    _func& bf = _basisFunction;

    if (i == 0)
      return [this,&bf](double x1, double x2, double x3) 
            {return (bf(x1+_eps,x2,x3) - bf(x1,x2,x3))/_eps;};
    
    if (i == 1)
      return [this,&bf](double x1, double x2, double x3) 
            {return (bf(x1,x2 + _eps,x3) - bf(x1,x2,x3))/_eps;};

    if (i == 2)
      return [this,&bf](double x1, double x2, double x3) 
            {return (bf(x1,x2,x3+_eps) - bf(x1,x2,x3))/_eps;};

    throw 0;
  }

}
