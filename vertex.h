// JOSH WINTON
// CSCI 335 ASSIGNMENT 4
// VERTEX CLASS

#ifndef VERTEX_H
#define VERTEX_H

#include <vector>

using namespace std;

// Used to store edges in adjacency list
struct Connection {
  int vertex_num;
  double weight;
};

// Data structure for storing vertices with edges
class Vertex {
public:
  int vertex_num_; // Vertex number as given in input
  bool known; // used for dijkstra
  int dist; // used for dijkstra
  Vertex* path = nullptr; // holds next vertex in shortest path
  vector<Connection> adjacencies_; // stores adjacency lists for graph representation

  // single parameter constructor
  Vertex(int vertex_num){
    vertex_num_ = vertex_num;
  }

  // prints all adjacencies for a given vertex
  void printAdjacencies(){
    std::cout << vertex_num_ << ":  ";
    for (size_t i = 0; i < adjacencies_.size(); i++) {
      std::cout << "vertex_num:" << adjacencies_[i].vertex_num << ", weight: " << adjacencies_[i].weight << "; ";
    }
    std::cout << '\n';
  }

  // adds new adjacency to vertex
  void addAdjacency(Connection new_adjacency){
    adjacencies_.push_back(new_adjacency);
  }

  // given another vertex's number, see whether it's adjacent
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
