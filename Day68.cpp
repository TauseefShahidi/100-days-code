// Day 68 - Question 1: Topological Sort (Kahnâ€™s BFS Algorithm)
// Close
// Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    vector<int> indegree(n, 0);

    // Directed edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;

    // Add all nodes with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // Kahn's Algorithm
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int next : graph[node]) {
            indegree[next]--;

            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    return 0;
}