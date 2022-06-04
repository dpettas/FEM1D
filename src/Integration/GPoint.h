#ifndef _FEM_GPOINT_INCLUDED_
#define _FEM_GPOINT_INCLUDED_


namespace FEM 
{




  template < typename ...Tv>
  class GPoint 
  {
    public: 

      GPoint();
      GPoint(double weight, Tv...);

      constexpr int size() const;

    private: 

      double  _weight;
      double coors[sizeof...(Tv)];
  };

}
#endif
