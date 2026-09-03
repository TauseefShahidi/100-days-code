// Day 67 - Question 1: Topological Sort (DFS)
// Close
// Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node, vector<vector<int>>& graph,
         vector<bool>& visited, stack<int>& st) {
    
    visited[node] = true;

    for (int next : graph[node]) {
        if (!visited[next]) {
            dfs(next, graph, visited, st);
        }
    }

    // Add after visiting all neighbours
    st.push(node);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);

    // Directed graph
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    vector<bool> visited(n, false);
    stack<int> st;

    // DFS for all nodes
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited, st);
        }
    }

    // Print topological order
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}