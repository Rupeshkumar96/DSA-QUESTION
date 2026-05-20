// adjacency_list.cpp
#include <iostream>
using namespace std;

struct Node {
    int vertex;
    Node* next;
};

class Graph {
private:
    int vertices;
    Node** adjList;

public:
    Graph(int v) {
        vertices = v;
        adjList = new Node*[vertices];
        for (int i = 0; i < vertices; i++) {
            adjList[i] = NULL;
        }
    }

    void addEdge(int u, int v) {
        // Add edge from u to v
        Node* newNode = new Node;
        newNode->vertex = v;
        newNode->next = adjList[u];
        adjList[u] = newNode;

        // Add edge from v to u (for undirected graph)
        newNode = new Node;
        newNode->vertex = u;
        newNode->next = adjList[v];
        adjList[v] = newNode;
    }

    void display() {
        cout << "Adjacency List:" << endl;
        for (int i = 0; i < vertices; i++) {
            cout << "Vertex " << i << ": ";
            Node* temp = adjList[i];
            while (temp != NULL) {
                cout << temp->vertex << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    ~Graph() {
        for (int i = 0; i < vertices; i++) {
            Node* temp = adjList[i];
            while (temp != NULL) {
                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
        }
        delete[] adjList;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    g.display();

    return 0;
}
