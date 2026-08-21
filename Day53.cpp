// Day 53 - Question 1: Print Binary Tree Vertical Order
// Close
// Problem Statement:
// Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

// Input Format:
// - First line contains integer N (number of nodes)
// - Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

// Output Format:
// - Print nodes column by column from leftmost to rightmost vertical line

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 4
// 2
// 1 5 6
// 3
// 7

// Explanation:
// Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.

#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Build tree from level-order input
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return nullptr;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < n) {
        Node* current = q.front();
        q.pop();

        // Left child
        if (i < n && arr[i] != -1) {
            current->left = new Node(arr[i]);
            q.push(current->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = new Node(arr[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// Vertical Order Traversal
void verticalOrder(Node* root) {
    if (root == nullptr)
        return;

    // horizontal distance -> nodes
    map<int, vector<int>> vertical;

    // node, horizontal distance
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        Node* node = current.first;
        int hd = current.second;

        vertical[hd].push_back(node->data);

        if (node->left)
            q.push({node->left, hd - 1});

        if (node->right)
            q.push({node->right, hd + 1});
    }

    // Print from leftmost to rightmost
    for (auto column : vertical) {
        for (int value : column.second) {
            cout << value << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}