// Day 61 - Question 1: Graph Representation Using Adjacency Matrix
// Close
// Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
// The graph may be directed or undirected.

// Input:
// - n (vertices)
// - m (edges)
// - m pairs (u, v)

// Output:
// - n x n adjacency matrix


#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int graph[n][n] = {0};

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        graph[u][v] = 1;
        graph[v][u] = 1;   // Remove this line for directed graph
    }

    // Print adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}