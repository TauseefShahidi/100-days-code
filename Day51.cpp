// Day 51 - Question 1: Lowest Common Ancestor in BST
// Close
// Problem Statement:
// Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers
// - Third line contains two node values

// Output Format:
// - Print the LCA value

// Example:
// Input:
// 7
// 6 2 8 0 4 7 9
// 2 8

// Output:
// 6

#include <iostream>
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

// Insert into BST
Node* insert(Node* root, int x) {
    if (root == NULL)
        return new Node(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

// Find LCA
Node* findLCA(Node* root, int p, int q) {
    if (root == NULL)
        return NULL;

    // Both values are smaller
    if (p < root->data && q < root->data)
        return findLCA(root->left, p, q);

    // Both values are greater
    if (p > root->data && q > root->data)
        return findLCA(root->right, p, q);

    // They are on different sides
    // or root is one of p or q
    return root;
}

int main() {
    int n;
    cin >> n;

    Node* root = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    int p, q;
    cin >> p >> q;

    Node* ans = findLCA(root, p, q);

    cout << ans->data;

    return 0;
}