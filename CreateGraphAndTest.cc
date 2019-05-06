// JOSH WINTON
// CSCI 335 ASSIGNMENT 4
// MAIN FILE FOR PART 1

#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "Graph.h"
using namespace std;

int main(int argc, char **argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <GraphFilename> <QueryFilename>" << endl;
    return 0;
  }

  const string graph_filename(argv[1]);
  const string query_filename(argv[2]);

  Graph my_graph;
  my_graph.fillGraph(graph_filename);
  my_graph.printGraph();
  my_graph.Query(query_filename);
}
