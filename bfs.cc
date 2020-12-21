#include "graph.h"
#include <iostream>
#include <queue>

void BFS(Graph &G, int source) {
    std::queue<int> q;
    q.push(source);
    G.SetVisited(source);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        std::cout << "Visiting: " << v << std::endl;

        for (auto &u : G.Adj(v)) {
            if (!G.IsVisited(u)) {
                q.push(u);
                G.SetVisited(u);
            }
        }    
    }
}

int main(int argc, char **argv) {
    std::ifstream ifs(argv[1]);
    int source = std::stoi(argv[2]);

    Graph G(ifs);
    BFS(G, source);

    return 1;
}
