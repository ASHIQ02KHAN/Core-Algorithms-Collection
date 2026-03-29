/*
Algorithm Name: Breadth-First Search (BFS)

Category: Graph Traversal
Technique: Level Order Traversal (Queue)

Description:
BFS explores the graph level by level starting from a source node.
It uses a queue to visit all neighbors before going deeper.

Time Complexity:
- O(V + E)

Space Complexity:
- O(V)

Use Case:
- Shortest path in unweighted graph
- Level order traversal
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<vector<int>> &adj, int V) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);

    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    bfs(0, adj, V);

    return 0;
}
