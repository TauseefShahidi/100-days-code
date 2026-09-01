// Day 66 - Question 1: Cycle Detection in Directed Graph
// Close
// Problem: Detect cycle in directed graph using DFS and recursion stack.

// Output:
// - YES if cycle exists

#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, vector<vector<int>>& graph,
         vector<bool>& visited, vector<bool>& path) {

    visited[node] = true;
    path[node] = true;

    for (int next : graph[node]) {

        // If node is not visited, visit it
        if (!visited[next]) {
            if (dfs(next, graph, visited, path))
                return true;
        }

        // Node is already in current recursion path
        else if (path[next]) {
            return true;
        }
    }

    // Remove from current recursion path
    path[node] = false;

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);

    // Directed edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
    }

    vector<bool> visited(n, false);
    vector<bool> path(n, false);

    bool cycle = false;

    // Check all components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, graph, visited, path)) {
                cycle = true;
                break;
            }
        }
    }

    if (cycle)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}