// Day 79 - Question 1: Single Source Shortest Path using Dijkstra’s Algorithm
// Close
// Problem Statement
// Find shortest distances from source vertex in a weighted graph with non-negative weights.

// Input Format
// n m
// u v w
// source

// Output Format
// Distances to all vertices.

// Sample Input
// 5 6
// 1 2 2
// 1 3 4
// 2 3 1
// 2 4 7
// 3 5 3
// 4 5 1
// 1

// Sample Output
// 0 2 3 9 6

// Explanation
// Shortest distances computed via priority queue.

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);

    // Build graph
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int source;
    cin >> source;

    vector<int> dist(n + 1, INT_MAX);

    // {distance, vertex}
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // Ignore old distance
        if (distance > dist[node])
            continue;

        for (auto edge : graph[node]) {
            int next = edge.first;
            int weight = edge.second;

            if (dist[node] + weight < dist[next]) {
                dist[next] = dist[node] + weight;
                pq.push({dist[next], next});
            }
        }
    }

    // Print distances
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            cout << -1;
        else
            cout << dist[i];

        if (i < n)
            cout << " ";
    }

    return 0;
}