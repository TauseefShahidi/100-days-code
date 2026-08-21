// Day 54 - Question 1: Zigzag Traversal
// Close
// Problem Statement:
// Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 indicates NULL)

// Output Format:
// - Print traversal in zigzag order

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 1 3 2 4 5 6 7

// Explanation:
// Level 1 is printed left-to-right, level 2 right-to-left, and so on.


#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
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

        if (i < n && arr[i] != -1) {
            current->left = new Node(arr[i]);
            q.push(current->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            current->right = new Node(arr[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// Zigzag Traversal
void zigzagTraversal(Node* root) {
    if (root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++) {
            Node* current = q.front();
            q.pop();

            level.push_back(current->data);

            if (current->left)
                q.push(current->left);

            if (current->right)
                q.push(current->right);
        }

        if (!leftToRight)
            reverse(level.begin(), level.end());

        for (int value : level)
            cout << value << " ";

        leftToRight = !leftToRight;
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Node* root = buildTree(arr, n);

    zigzagTraversal(root);

    return 0;
}