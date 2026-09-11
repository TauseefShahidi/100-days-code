// Day 76 - Question 1: Count Connected Components (Undirected Graph)
// Close
// Problem Statement
// Using DFS or BFS, count number of connected components.

// Input Format
// n m
// edges

// Output Format
// Number of connected components.

// Sample Input
// 6 3
// 1 2
// 2 3
// 5 6

// Sample Output
// 3

// Explanation
// Components: {1,2,3}, {4}, {5,6}



#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;

    for (int next : graph[node]) {
        if (!visited[next]) {
            dfs(next, graph, visited);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);

    // Build graph
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);
    int components = 0;

    // Find all components
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components++;
            dfs(i, graph, visited);
        }
    }

    cout << components;

    return 0;
}