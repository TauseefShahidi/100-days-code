// Day 65 - Question 1: Cycle Detection in Undirected Graph (DFS)
// Close
// Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

// Output:
// - YES or NO

#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int parent, vector<vector<int>>& graph,
         vector<bool>& visited) {

    visited[node] = true;

    for (int next : graph[node]) {

        // Visit unvisited node
        if (!visited[next]) {
            if (dfs(next, node, graph, visited))
                return true;
        }

        // Already visited and not parent => cycle
        else if (next != parent) {
            return true;
        }
    }

    return false;
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
        graph[v].push_back(u);
    }

    vector<bool> visited(n, false);

    bool cycle = false;

    // Check all components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, graph, visited)) {
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