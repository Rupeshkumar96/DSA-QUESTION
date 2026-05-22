// indegree_outdegree.cpp
#include <iostream>
using namespace std;

class DirectedGraph {
private:
    int vertices;
    int** adjMatrix;

public:
    DirectedGraph(int v) {
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
    }

    void findInOutDegrees() {
        cout << "Vertex\tIn-degree\tOut-degree" << endl;

        for (int i = 0; i < vertices; i++) {
            int inDegree = 0, outDegree = 0;

            // Calculate out-degree
            for (int j = 0; j < vertices; j++) {
                if (adjMatrix[i][j] == 1) {
                    outDegree++;
                }
            }

            // Calculate in-degree
            for (int j = 0; j < vertices; j++) {
                if (adjMatrix[j][i] == 1) {
                    inDegree++;
                }
            }

            cout << i << "\t" << inDegree << "\t\t" << outDegree << endl;
        }
    }
};

int main() {
    DirectedGraph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);

    g.findInOutDegrees();

    return 0;
}
