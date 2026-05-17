#include <iostream>
#include <queue>
using namespace std;

int main() {
    int graph[4][4] = {
        {0,1,1,0},
        {1,0,1,1},
        {1,1,0,0},
        {0,1,0,0}
    };

    bool visited[4] = {false};
    queue<int> q;

    visited[0] = true;
    q.push(0);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for(int i=0;i<4;i++) {
            if(graph[node][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}