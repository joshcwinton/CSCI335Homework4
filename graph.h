// JOSH WINTON
// GRAPH CLASS FOR USE IN CSCI 335 ASSIGNMENT 4

#ifndef GRAPH_H
#define GRAPH_H

#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include "Vertex.h"

using namespace std;

// helper function for parsing input
vector<string> split (const string &s, char delim) {
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

// data structure for representing graph, includes algorithms
class Graph {
public:
  // single parameter constructor
  Graph(int size) { size_ = size; }

  // zero parameter constructor
  Graph(){
    size_ = 0;
  }

  // prints graph
  void printGraph() {
    for (size_t i = 0; i < vertices_.size(); i++) {
      vertices_[i].printAdjacencies();
    }
  }

  // helper fnction for filling in graph
  void addConnections(string &db_line) {
    vector<string> split_line = split(db_line, ' ');
    int current_vertex_num = stoi(split_line[0]);
    Vertex current_vertex(current_vertex_num);
    for (size_t i = 1; i < split_line.size()-1; i+=2) {
      Connection a = {stoi(split_line[i]), stod(split_line[i+1])};
      current_vertex.addAdjacency(a);
    }
    vertices_.push_back(current_vertex);
    size_++;
  }

  // given a file with adjacency list, fill graph
  void fillGraph(string graph_filename){
    string db_line;
    ifstream db_file(graph_filename);
    if (db_file.is_open()) {
      getline(db_file, db_line);
      while (getline(db_file, db_line)) {
        addConnections(db_line);
      }
    }
  }

  // given two vertices check if they're connected, print weight if they are
  void printConnection(int a, int b){
    Vertex current_vertex = vertices_[a-1];
    double val = current_vertex.findAdjacency(b);
    if (val == 0) {
      cout << a << ' ' << b << ": Not Connected\n";
    } else {
      cout << a << ' ' << b << ": Connected, weight of edge is " << val << endl;
    }
  }

  // deals with query file
  void Query(string query_filename) {
    string db_line;
    ifstream db_file(query_filename);
    if (db_file.is_open()) {
      while (getline(db_file, db_line)) {
        vector<string> v = split(db_line, ' ');
        printConnection(stoi(v[0]), stoi(v[1]));
      }
    }
  }

  int getSize(){
    return size_;
  }

  // given vertex number gets pointer to it
  Vertex* getVertex(int n){
    return &vertices_[n-1];
  }

  // [dijkstra] Checks whether there are unknowns left in the graph
  bool has_unknown(){
    for (size_t i = 0; i < vertices_.size(); i++) {
      if(vertices_[i].known == false){
        return true;
      }
    }
    return false;
  }

  // finds and returns a pointer to smallest unknown
  Vertex* findSmallestUnknown(){
    int min = 0;
    int min_dist = 100000000;
    for (size_t i = 0; i < vertices_.size(); i++) {
      if((vertices_[i].dist < min_dist) && (!vertices_[i].known)){
        min = i;
        min_dist = vertices_[i].dist;
      }
    }
    return &vertices_[min];
  }

  // djikstras algorithm
  void dijkstra(int start){
    Vertex* current_vertex = getVertex(start);

    for (size_t i = 0; i < size_; i++) {
      vertices_[i].dist = 1000000;
      vertices_[i].known = false;
    }

    current_vertex->dist = 0;

    while(has_unknown()){
      Vertex* v = findSmallestUnknown();
      v->known = true;

      for (size_t i = 0; i < v->adjacencies_.size(); i++) {
        Vertex* w = getVertex(v->adjacencies_[i].vertex_num);
        if(w->known == false){
          int cvw = v->adjacencies_[i].weight;
          cout << v->vertex_num_ << ":" << cvw << endl;
          cout << v->dist + cvw << endl;
          if (v->dist + cvw < w->dist) {

            w->dist = v->dist + cvw;
            w->path = v;
          }
        }
      }
    }

    for (size_t i = 0; i < vertices_.size(); i++) {
      cout << vertices_[i].vertex_num_ << ": " << vertices_[i].dist << endl;
    }
    cout <<vertices_[1].vertex_num_;
    cout << vertices_[1].path->vertex_num_;
  }

  // [NOT WORKING] prints a path to vertex v from start vertex
  void printPath(Vertex* v){
    cout << "yes!" << endl;
    if(v->path != nullptr){
      cout << v->vertex_num_ << endl;
      printPath(v->path);
      cout << " to ";
    }
    cout << v->vertex_num_ << endl;
  }

private:
  int size_;
  vector<Vertex> vertices_;
};

#endif // GRAPH_H
