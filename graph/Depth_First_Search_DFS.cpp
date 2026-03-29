/*
Algorithm Name: Depth-First Search (DFS)

Category: Graph Traversal
Technique: Recursion / Stack

Description:
DFS explores as far as possible along each branch before backtracking.

Time Complexity:
- O(V + E)

Space Complexity:
- O(V)

Use Case:
- Cycle detection
- Path finding
*/

#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
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

    vector<bool> visited(V, false);
    dfs(0, adj, visited);

    return 0;
}
