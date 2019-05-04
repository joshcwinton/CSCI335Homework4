#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

// Data structure for storing vertces in adjacency lists
struct Node {
  int val;
  Node* next;
};

// Data structure to store graph edges
struct Edge {
  int src, dest;
  double weight;
};

class Graph {
  // Function to allocate new node of adjacency list
  Node* getAdjListNode(int dest, Node* head){
    Node* newNode = new Node;
    newNode->val = dest;

    // Point new node to current head
    newNode->next = head;

    return newNode;
  }

  int N; // Number of nodes in graph

public:
  // Array of pointers to Node to represent adjacency list
  Node **head;

  // Constructor
  Graph(vector<Edge> edges, int n, int N){
    // allocate memory
    head = new Node*[N+1]();
    this->N = N;

    // initialize head pointer for all vertices
    for (int i = 1; i <= N; i++){
      head[i] = nullptr;
    }

    // add edges to the directed Graph
    for (unsigned i = 0; i < n; i++){
      int src = edges[i].src;
      int dest = edges[i].dest;

      // insert in the beginning
      Node* newNode = getAdjListNode(dest, head[src]);

      // point head pointer to new node
      head[src] = newNode;

    }
  }

  // Destructor
  ~Graph() {
    for (int i = 1; i < N; i++){
      delete[] head[i];
    }
    delete[] head;
  }
};

void printList(Node* ptr){
  while (ptr != nullptr){
    cout << " -> " << ptr->val << " ";
    ptr = ptr->next;
  }
  cout << endl;
}

vector<string> split (const string &s, char delim) {
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

void addEdges(string db_line, vector<Edge> edges){
  int edgeNum;
  Edge e = {0, 0, 0};
  vector<string> v = split(db_line, ' ');
  edgeNum = stoi(v[0]);
  for(int i = 1; i < v.size(); i++){
    if(i%2==1){
      e.src = edgeNum;
      e.dest = stoi(v[i]);
      e.weight = stoi(v[i+1]);
      edges.push_back(e);
    }
  }
}



int main(int argc, char **argv){
  if (argc != 3){
    cout << "Usage: " << argv[0] << " <GraphFilename> <QueryFilename>" << endl;
    return 0;
  }

  const string graph_filename(argv[1]);
  const string query_filename(argv[2]);

  int N;
  vector<Edge> edges;
  string db_line;
  ifstream db_file(graph_filename);
  if (db_file.is_open()){
    getline(db_file, db_line);
    N = stoi(db_line);
    std::cout << N << '\n';
    while (getline(db_file, db_line)) {
      // addEdges(db_line, edges);
    }
  }



  // = {{1, 2, 0.2}, {1, 4, 10.1}, {1, 5, 0.5}};

  int n = sizeof(edges)/sizeof(edges[1]);

  Graph graph(edges, n, N);

  for (int i = 1; i <= N; i++)
    {
        // print given vertex
        cout << i << " --";

        // print all its neighboring vertices
        printList(graph.head[i]);
    }

  return 0;
}
