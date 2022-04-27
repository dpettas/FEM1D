#include "Mesh1D.h"

FEM::Mesh1D::Mesh1D(){
  xlow      = 0.0; 
  xmax      = 1.0;
  num_nodes = 100;
  x         = new double [num_nodes];

  for (int i = 0; i < num_nodes; ++i) x[i] = xlow + static_cast<double>(i)/num_nodes * (xmax - xlow);

}

FEM::Mesh1D::Mesh1D(double low_, double max_, int num_nodes_){
  xlow      = low_; 
  xmax      = max_;
  num_nodes = num_nodes_;

  x = new double [num_nodes];
  for (int i = 0; i < num_nodes; ++i) x[i] = xlow + static_cast<double>(i)/num_nodes * (xmax - xlow);
}

FEM::Mesh1D::~Mesh1D(){
  delete [] x;
}

