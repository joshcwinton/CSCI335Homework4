#include <iostream>
#include "Graph.h"

using namespace std;

int main(int argc, char **argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <GraphFilename> <Starting_Vertex>" << endl;
    return 0;
  }

  const string graph_filename(argv[1]);
  const int start_v(stoi(argv[2]));

  Graph my_graph;
  my_graph.fillGraph(graph_filename);
  my_graph.printGraph();
  my_graph.dijkstra(start_v);
  Vertex* v = my_graph.getVertex(7);
  my_graph.printPath(v);
}
