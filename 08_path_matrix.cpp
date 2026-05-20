// path_matrix.cpp
#include <iostream>
using namespace std;

class Graph {
private:
    int vertices;
    int** adjMatrix;
    int** pathMatrix;

public:
    Graph(int v) {
        vertices = v;
        adjMatrix = new int*[vertices];
        pathMatrix = new int*[vertices];
        for (int i = 0; i < vertices; i++) {
            adjMatrix[i] = new int[vertices];
            pathMatrix[i] = new int[vertices];
            for (int j = 0; j < vertices; j++) {
                adjMatrix[i][j] = 0;
                pathMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
    }

    void computePathMatrix() {
        // Initialize path matrix with adjacency matrix
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                pathMatrix[i][j] = adjMatrix[i][j];
            }
        }

        // Floyd-Warshall algorithm to find all pairs reachability
        for (int k = 0; k < vertices; k++) {
            for (int i = 0; i < vertices; i++) {
                for (int j = 0; j < vertices; j++) {
                    if (pathMatrix[i][k] && pathMatrix[k][j]) {
                        pathMatrix[i][j] = 1;
                    }
                }
            }
        }
    }

    void displayPathMatrix() {
        computePathMatrix();

        cout << "Path Matrix (reachability):" << endl;
        cout << "   ";
        for (int i = 0; i < vertices; i++) {
            cout << i << " ";
        }
        cout << endl;

        for (int i = 0; i < vertices; i++) {
            cout << i << "  ";
            for (int j = 0; j < vertices; j++) {
                cout << pathMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~Graph() {
        for (int i = 0; i < vertices; i++) {
            delete[] adjMatrix[i];
            delete[] pathMatrix[i];
        }
        delete[] adjMatrix;
        delete[] pathMatrix;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.displayPathMatrix();

    return 0;
}
