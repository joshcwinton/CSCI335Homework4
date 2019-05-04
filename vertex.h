#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
using namespace std;

class ConnectedVertex {
public:
  ConnectedVertex(int connected_vert, double connected_weight){
    connected_vert_ = connected_vert;
    connected_weight_ = connected_weight;
  }
private:
  int connected_vert_;
  double connected_weight_;
};

class Vertex {
public:
  Vertex(int vertex_num){
    vertex_num_=vertex_num;
  }

  bool AddConnected(int vertex_num){
    // array_.push_back(new_vert);
    return true;
  }
private:
  int vertex_num_;
  std::vector<ConnectedVertex> array_;
};
#endif // VERTEX_H
