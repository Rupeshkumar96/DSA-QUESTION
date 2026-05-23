// count_edges.cpp
#include <iostream>
using namespace std;

class Graph {
private:
    int vertices;
    int** adjMatrix;

public:
    Graph(int v) {
        vertices = v;
        adjMatrix = new int*[vertices];
        for (int i = 0; i < vertices; i++) {
            adjMatrix[i] = new int[vertices];
            for (int j = 0; j < vertices; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    int countEdges() {
        int edgeCount = 0;
        for (int i = 0; i < vertices; i++) {
            for (int j = i; j < vertices; j++) {
                if (adjMatrix[i][j] == 1) {
                    edgeCount++;
                }
            }
        }
        return edgeCount;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);

    cout << "Number of edges: " << g.countEdges() << endl;

    return 0;
}
