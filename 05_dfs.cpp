#include <iostream>
using namespace std;

void dfs(int graph[4][4], bool visited[], int node) {
    visited[node] = true;
    cout << node << " ";

    for(int i=0;i<4;i++) {
        if(graph[node][i] && !visited[i])
            dfs(graph, visited, i);
    }
}

int main() {
    int graph[4][4] = {
        {0,1,1,0},
        {1,0,1,1},
        {1,1,0,0},
        {0,1,0,0}
    };

    bool visited[4] = {false};

    dfs(graph, visited, 0);
}