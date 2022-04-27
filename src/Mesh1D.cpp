#include "Mesh1D.h"

FEM::Mesh1D::Mesh1D(){
  xlow      = 0.0; 
  xmax      = 1.0;
  num_nodes = 100;

  createNodes();
}

FEM::Mesh1D::Mesh1D(double low_, double max_, int num_nodes_){
  xlow      = low_; 
  xmax      = max_;
  num_nodes = num_nodes_;

  createNodes();
}

FEM::Mesh1D::~Mesh1D(){
  delete [] nodes;
  nodes = nullptr;
}

void FEM::Mesh1D::createNodes(){
  nodes     = new Node [num_nodes];
  for (int i = 0; i < num_nodes; ++i) {
    double x = xlow + static_cast<double>(i)/(num_nodes-1) * (xmax - xlow);
    nodes[i].setNodeId(i);
    nodes[i].setLocation(x);
  }

}

void FEM::Mesh1D::setSpaceModifier(Node* (*mod) (int,const Node*) ){

  nodes = mod(this->getNumNodes(), this->getNodes());
}
