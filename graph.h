#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
using namespace std;

#endif // GRAPH_H

class Graph {
public:
  Graph(){
      vertices_ = 0;
  }

  Graph(Vertex v){
    vertices_ = 1;
    array_.push_back(v);
  }

  bool InsertVertex(Vertex v){
    return 0;
  }

  Vertex* FindVertex(Vertex v){
    return nullptr;
  }
  
private:
  std::vector<Vertex> array_;
  int vertices_;
};
