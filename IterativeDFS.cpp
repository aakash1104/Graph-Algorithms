// Author: Aakash Prabhu
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// DFS Traversal of an undirected and unweighted graph.
void createAndAddEdge(vector <int> adjList[], int u, int v){
  adjList[u].push_back(v);
  adjList[v].push_back(u); // do this because undirected graph
} // createAndAddEdge(vector <int> List[], int u, int v)

void DFS(vector <int> adjList[], vector <bool> visitedVertex, int source){
  stack <int> S; //set up Queue for BFS
  int v;
  S.push(source);
  while (!S.empty()){
    v = S.top();
    visitedVertex.at(v) = true;
    S.pop();
    cout << v << " "; // Print Vertex
    for (vector<int>::iterator it = adjList[v].begin(); it != adjList[v].end(); it++) // Go as far as we can go and then backtrack
      if (!visitedVertex.at(*it)){
        S.push(*it); // Push unvisted vertex onto the stack
        visitedVertex.at(*it) = true;
      } // if not visited
  } // While Stack is not empty
  cout << endl;
} // DFS

int main (void){
  // Idea is to implement the adjacency list as an array of vectors:
  const int numVertices = 5; // 6 vertices (0,1,2,3,4,5)
  int source = 0;
  vector<int> adjList[numVertices]; // Create an array of vectors
  vector <bool> visitedVertex(numVertices, false);
  createAndAddEdge(adjList, 0, 1);
  createAndAddEdge(adjList, 0, 2);
  createAndAddEdge(adjList, 1, 3);
  createAndAddEdge(adjList, 1, 4);
  createAndAddEdge(adjList, 3, 3);
  createAndAddEdge(adjList, 4, 4);
  createAndAddEdge(adjList, 2, 2);
  DFS(adjList, visitedVertex, source); // Perform DFS given graph G and a source s
  //Should Print: 0 2 1 4 3

} // main()
