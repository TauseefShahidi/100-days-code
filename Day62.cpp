// Day 62 - Question 1: Graph Representation Using Adjacency List
// Close
// Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

// Input:
// - n (vertices)
// - m (edges)
// - edges (u, v)

// Output:
// - List of adjacency lists for each vertex

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);   // Remove this for directed graph
    }

    // Print adjacency list
    for (int i = 0; i < n; i++) {
        cout << i << ": ";

        for (int node : graph[i]) {
            cout << node << " ";
        }

        cout << endl;
    }

    return 0;
}