// Day 78 - Question 1: Minimum Spanning Tree using Prim’s Algorithm
// Close
// Problem Statement
// Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

// Input Format
// n m
// u v w
// ...

// Output Format
// Total weight of MST.

// Sample Input
// 4 5
// 1 2 3
// 1 3 5
// 2 3 1
// 2 4 4
// 3 4 2

// Sample Output
// 6

// Explanation
// One possible MST edges: (2-3), (3-4), (1-2)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);

    // Store graph
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    // {weight, node}
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    vector<bool> visited(n + 1, false);

    pq.push({0, 1});

    int totalWeight = 0;

    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (visited[node])
            continue;

        visited[node] = true;
        totalWeight += weight;

        for (auto edge : graph[node]) {
            int next = edge.first;
            int edgeWeight = edge.second;

            if (!visited[next]) {
                pq.push({edgeWeight, next});
            }
        }
    }

    cout << totalWeight;

    return 0;
}