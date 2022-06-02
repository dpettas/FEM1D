#ifndef _FEM_IGAUSSPOINT_INCLUDED_ 
#define _FEM_IGAUSSPOINT_INCLUDED_ 


class IGaussPoint 
{
  public: 
    virtual int      size()      const noexcept = 0;
    virtual double*  position()  const noexcept = 0;
    virtual double   weight()    const noexcept = 0; 
};



#endif
