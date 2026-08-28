// Day 63 - Question 1: Depth First Search (DFS)
// Close
// Problem: Perform DFS starting from a given source vertex using recursion.

// Input:
// - n
// - adjacency list
// - starting vertex s

// Output:
// - DFS traversal order


#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& graph,
         vector<bool>& visited) {

    visited[node] = true;
    cout << node << " ";

    for (int next : graph[node]) {
        if (!visited[next]) {
            dfs(next, graph, visited);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);   // Remove for directed graph
    }

    int s;
    cin >> s;

    vector<bool> visited(n, false);

    // Start DFS
    dfs(s, graph, visited);

    return 0;
}

