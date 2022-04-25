#include "Node.h"


namespace FEM{

  Node::Node(){
    node_id = -1;
    p = nullptr;

  }


  Node::Node(int node_id_, const Point* p_){

    node_id       = node_id_;
    p             = const_cast<Point*>(p_);
    point_created = false;
  }


  Node::Node(int node_id_, double x_){
    node_id       = node_id_;
    point_created = true;
    p             = new Point1D(x_);
  }

  Node::~Node(){
    if (point_created) delete p;
  }


  Node::Node(const Node& rhs){
    node_id       = rhs.getNodeId();
    p             = new Point1D(*rhs.getPoint()->getCoordinates());
    point_created = true;
  }

  bool Node::hasTheSameId(const Node& other){

    return other.getNodeId() == this->getNodeId();
  }


}
