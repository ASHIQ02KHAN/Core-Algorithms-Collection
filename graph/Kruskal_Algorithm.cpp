/*
Algorithm Name: Kruskal's Algorithm

Category: Minimum Spanning Tree (MST)
Technique: Greedy + Disjoint Set (Union-Find)

Description:
Builds MST by selecting the smallest edges while avoiding cycles.

Time Complexity:
- O(E log E)

Space Complexity:
- O(V)

Use Case:
- Network design
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

vector<int> parent;

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unionSet(int a, int b) {
    parent[find(a)] = find(b);
}

void kruskal(int V, vector<Edge> &edges) {
    sort(edges.begin(), edges.end(), compare);

    parent.resize(V);
    for (int i = 0; i < V; i++)
        parent[i] = i;

    for (auto &e : edges) {
        if (find(e.u) != find(e.v)) {
            cout << e.u << " - " << e.v << " : " << e.weight << endl;
            unionSet(e.u, e.v);
        }
    }
}

int main() {
    int V = 4;
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5},
        {1, 3, 15}, {2, 3, 4}
    };

    kruskal(V, edges);

    return 0;
}
