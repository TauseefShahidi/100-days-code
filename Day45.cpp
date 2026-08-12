// Problem Statement:
// Find the height (maximum depth) of a given binary tree.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 represents NULL)

// Output Format:
// - Print the height of the tree

// Example:
// Input:
// 7
// 1 2 3 4 5 -1 -1

// Output:
// 3

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

int height(Node* root) {
    if (root == NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

int main() {
    int N;
    cin >> N;

    vector<int> a(N);

    for (int i = 0; i < N; i++)
        cin >> a[i];

    if (N == 0 || a[0] == -1) {
        cout << 0;
        return 0;
    }

    Node* root = new Node(a[0]);

    queue<Node*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < N) {
        Node* cur = q.front();
        q.pop();

        // Left child
        if (i < N && a[i] != -1) {
            cur->left = new Node(a[i]);
            q.push(cur->left);
        }
        i++;

        // Right child
        if (i < N && a[i] != -1) {
            cur->right = new Node(a[i]);
            q.push(cur->right);
        }
        i++;
    }

    cout << height(root);

    return 0;
}