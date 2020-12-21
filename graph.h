#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <fstream>

class Graph {
private:
    int num_vertices;
    int num_edges;
    std::vector<std::vector<int>> adj_list;
    std::vector<bool> visited;

public:
    // Create an empty graph with @V vertices
    Graph(int V);
    // Create a graph from a file
    Graph(std::ifstream &ifs);
    // Add undirected edge between @u and @v
    void AddEdge(int u, int v);
    // Return the number of vertices;
    const int V();
    // Return the number of edges
    const int E();
    // Return vertices adjacent to @v
    std::vector<int> Adj(const int v);
    // Get if @v has been visited
    bool IsVisited(int v);
    // Set @v as visited
    void SetVisited(int v);
};

Graph::Graph(int V) {
    num_vertices = V;
    adj_list.resize(V);
    visited.resize(V);
}

Graph::Graph(std::ifstream &ifs) {
    ifs >> num_vertices;
    adj_list.resize(num_vertices);
    visited.resize(num_vertices);
    
    int u, v;
    while (ifs >> u >> v)
        AddEdge(u, v);

    for (int i = 0; i < num_vertices; i++)
        visited[i] = false;

}

void Graph::AddEdge(int u, int v) {
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
    num_edges++;
}

const int Graph::V() {
    return num_vertices;
}
const int Graph::E() {
    return num_edges;
}

std::vector<int> Graph::Adj(const int v) {
    return adj_list[v];
}

bool Graph::IsVisited(int v) {
    return visited[v];
}

void Graph::SetVisited(int v) {
    visited[v] = true;
}

#endif
