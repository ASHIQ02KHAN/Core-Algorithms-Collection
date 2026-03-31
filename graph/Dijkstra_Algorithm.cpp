/*
Algorithm Name: Dijkstra's Algorithm

Category: Shortest Path Algorithm
Technique: Greedy + Priority Queue

Description:
Finds the shortest path from a source node to all other nodes
in a weighted graph with non-negative weights.

Time Complexity:
- O((V + E) log V)

Space Complexity:
- O(V)

Use Case:
- GPS navigation
- Network routing
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9

void dijkstra(int V, vector<vector<pair<int, int>>> &adj, int src) {
    vector<int> dist(V, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        for (auto &neighbor : adj[node]) {
            int next = neighbor.first;
            int weight = neighbor.second;

            if (d + weight < dist[next]) {
                dist[next] = d + weight;
                pq.push({dist[next], next});
            }
        }
    }

    for (int i = 0; i < V; i++)
        cout << "Distance to " << i << ": " << dist[i] << endl;
}

int main() {
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);

    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 1});

    dijkstra(V, adj, 0);

    return 0;
}
