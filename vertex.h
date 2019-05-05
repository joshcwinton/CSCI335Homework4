#ifndef VERTEX_H
#define VERTEX_H

#include <vector>

using namespace std;

struct Connection {
  int vertex_num;
  double weight;
};

class Vertex {
public:
  int vertex_num_;
  bool known;
  int dist;
  Vertex* path = nullptr;
  vector<Connection> adjacencies_;

  Vertex(int vertex_num){
    vertex_num_ = vertex_num;
  }

  void printAdjacencies(){
    std::cout << vertex_num_ << ":  ";
    for (size_t i = 0; i < adjacencies_.size(); i++) {
      std::cout << "vertex_num:" << adjacencies_[i].vertex_num << ", weight: " << adjacencies_[i].weight << "; ";
    }
    std::cout << '\n';
  }

  void addAdjacency(Connection new_adjacency){
    adjacencies_.push_back(new_adjacency);
  }

  double findAdjacency(int adj){
    for (size_t i = 0; i < adjacencies_.size(); i++) {
      if(adjacencies_[i].vertex_num == adj){
        return adjacencies_[i].weight;
      }
    }
    return 0;
  }
};

#endif // VERTEX_H
