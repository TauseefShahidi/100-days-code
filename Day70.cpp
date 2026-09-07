// Day 70 - Question 1: Bellman-Ford Algorithm
// Close
// Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

// Input:
// - n vertices
// - m edges (u,v,w)

// Output:
// - Shortest distances OR NEGATIVE CYCLE

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int source;
    cin >> source;

    vector<int> dist(n, INT_MAX);
    dist[source] = 0;

    // Relax all edges n-1 times
    for (int i = 1; i <= n - 1; i++) {
        for (auto edge : edges) {

            if (dist[edge.u] != INT_MAX &&
                dist[edge.u] + edge.w < dist[edge.v]) {

                dist[edge.v] = dist[edge.u] + edge.w;
            }
        }
    }

    // Check for negative weight cycle
    for (auto edge : edges) {
        if (dist[edge.u] != INT_MAX &&
            dist[edge.u] + edge.w < dist[edge.v]) {

            cout << "NEGATIVE CYCLE";
            return 0;
        }
    }

    // Print shortest distances
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }

    return 0;
}