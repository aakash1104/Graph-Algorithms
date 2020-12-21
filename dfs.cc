#include "graph.h"
#include <iostream>
#include <queue>

void DFS(Graph &G, int source) {
    G.SetVisited(source);
    std::cout << "Visiting: " << source << std::endl;

    for (auto u : G.Adj(source))
        if (!G.IsVisited(u))
            DFS(G, u);    
}

int main(int argc, char **argv) {
    std::ifstream ifs(argv[1]);
    int source = std::stoi(argv[2]);

    Graph G(ifs);
    DFS(G, source);

    return 1;
}
