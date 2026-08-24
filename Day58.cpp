// Day 58 - Question 1: Build Tree from Inorder & Preorder
// Close
// Problem Statement:
// Construct a binary tree from given preorder and inorder traversal arrays.

// Input Format:
// - First line contains integer N
// - Second line contains preorder traversal
// - Third line contains inorder traversal

// Output Format:
// - Print postorder traversal of constructed tree

// Example:
// Input:
// 5
// 1 2 4 5 3
// 4 2 5 1 3

// Output:
// 4 5 2 3 1

// Explanation:
// Preorder identifies root, inorder splits left and right subtrees.


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

Node* buildTree(int preorder[], int inorder[],
                int inStart, int inEnd,
                int& preIndex,
                unordered_map<int, int>& pos) {

    if (inStart > inEnd)
        return nullptr;

    // First element in preorder is the root
    int rootValue = preorder[preIndex++];
    Node* root = new Node(rootValue);

    // Find root in inorder
    int index = pos[rootValue];

    // Build left subtree
    root->left = buildTree(preorder, inorder,
                           inStart, index - 1,
                           preIndex, pos);

    // Build right subtree
    root->right = buildTree(preorder, inorder,
                            index + 1, inEnd,
                            preIndex, pos);

    return root;
}

// Postorder: Left -> Right -> Root
void postorder(Node* root) {
    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    int n;
    cin >> n;

    int preorder[n];
    int inorder[n];

    for (int i = 0; i < n; i++)
        cin >> preorder[i];

    for (int i = 0; i < n; i++)
        cin >> inorder[i];

    // Store position of each value in inorder
    unordered_map<int, int> pos;

    for (int i = 0; i < n; i++)
        pos[inorder[i]] = i;

    int preIndex = 0;

    Node* root = buildTree(preorder, inorder,
                           0, n - 1,
                           preIndex, pos);

    postorder(root);

    return 0;
}
