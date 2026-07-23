/*
Algorithm Name: Prim's Algorithm

Category: Minimum Spanning Tree (MST)
Technique: Greedy + Priority Queue

Description:
Builds MST by starting from a node and adding the smallest edge
connecting the tree to a new vertex.

Time Complexity:
- O((V + E) log V)

Space Complexity:
- O(V)

Use Case:
- Network design
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9

void prim(int V, vector<vector<pair<int, int>>> &adj) {
    vector<int> key(V, INF);
    vector<bool> inMST(V, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (auto &neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
            }
        }
    }

    for (int i = 0; i < V; i++)
        cout << "Weight to node " << i << ": " << key[i] << endl;
}

int main() {
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);

    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});
    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});
    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});
    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});
    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});
    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    prim(V, adj);

    return 0;
}
