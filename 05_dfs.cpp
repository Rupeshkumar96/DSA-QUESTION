// dfs_matrix.cpp
#include <iostream>
#include <stack>
using namespace std;

class Graph {
private:
    int vertices;
    int** adjMatrix;

    void DFSUtil(int vertex, bool* visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[vertex][i] == 1 && !visited[i]) {
                DFSUtil(i, visited);
            }
        }
    }

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
        adjMatrix[v][u] = 1; // For undirected graph
    }

    void DFS(int startVertex) {
        bool* visited = new bool[vertices];
        for (int i = 0; i < vertices; i++) {
            visited[i] = false;
        }

        cout << "DFS Traversal starting from vertex " << startVertex << ": ";
        DFSUtil(startVertex, visited);
        cout << endl;

        delete[] visited;
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);

    g.DFS(0);

    return 0;
}
