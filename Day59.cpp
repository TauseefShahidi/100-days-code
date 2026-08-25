// Day 59 - Question 1: Build Tree from Inorder & Postorder
// Close
// Problem Statement:
// Construct a binary tree from given inorder and postorder traversal arrays.

// Input Format:
// - First line contains integer N
// - Second line contains inorder traversal
// - Third line contains postorder traversal

// Output Format:
// - Print preorder traversal of constructed tree

// Example:
// Input:
// 5
// 4 2 5 1 3
// 4 5 2 3 1

// Output:
// 1 2 4 5 3

// Explanation:
// Postorder gives root at end, inorder divides left and right subtrees.


#include <iostream>
#include <unordered_map>
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

Node* buildTree(int inorder[], int postorder[],
                int inStart, int inEnd,
                int& postIndex,
                unordered_map<int, int>& pos) {

    if (inStart > inEnd)
        return nullptr;

    // Last element of postorder is the root
    int rootValue = postorder[postIndex--];
    Node* root = new Node(rootValue);

    // Find root in inorder
    int index = pos[rootValue];

    // Build right subtree first
    root->right = buildTree(inorder, postorder,
                            index + 1, inEnd,
                            postIndex, pos);

    // Build left subtree
    root->left = buildTree(inorder, postorder,
                           inStart, index - 1,
                           postIndex, pos);

    return root;
}

// Preorder: Root -> Left -> Right
void preorder(Node* root) {
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    cin >> n;

    int inorder[n];
    int postorder[n];

    for (int i = 0; i < n; i++)
        cin >> inorder[i];

    for (int i = 0; i < n; i++)
        cin >> postorder[i];

    // Store positions of inorder elements
    unordered_map<int, int> pos;

    for (int i = 0; i < n; i++)
        pos[inorder[i]] = i;

    int postIndex = n - 1;

    Node* root = buildTree(inorder, postorder,
                           0, n - 1,
                           postIndex, pos);

    preorder(root);

    return 0;
}