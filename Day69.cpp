// Day 69 - Question 1: Dijkstraâ€™s Algorithm (Shortest Path)
// Close
// Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // graph[u] = {v, weight}
    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // Remove this for directed graph
    }

    int source;
    cin >> source;

    vector<int> dist(n, INT_MAX);

    // {distance, node}
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // Skip outdated distance
        if (distance > dist[node])
            continue;

        for (auto edge : graph[node]) {
            int next = edge.first;
            int weight = edge.second;

            // Relaxation
            if (dist[node] + weight < dist[next]) {
                dist[next] = dist[node] + weight;
                pq.push({dist[next], next});
            }
        }
    }

    // Print shortest distances
    for (int i = 0; i < n; i++) {
        cout << "Distance from " << source
             << " to " << i << " = ";

        if (dist[i] == INT_MAX)
            cout << "-1";
        else
            cout << dist[i];

        cout << endl;
    }

    return 0;
}