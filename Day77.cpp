// Day 77 - Question 1: Check if Graph is Connected
// Close
// Problem Statement
// Using BFS or DFS, check if the entire graph is connected.

// Input Format
// n m
// edges

// Output Format
// CONNECTED
// NOT CONNECTED

// Sample Input
// 4 2
// 1 2
// 3 4

// Sample Output
// NOT CONNECTED



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

    // Start DFS from node 1
    dfs(1, graph, visited);

    // Check if every node was visited
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << "NOT CONNECTED";
            return 0;
        }
    }

    cout << "CONNECTED";

    return 0;
}