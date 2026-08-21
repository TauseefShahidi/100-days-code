// Problem Statement:
// Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 represents NULL)
// - Third line contains two node values

// Output Format:
// - Print the LCA value

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7
// 4 5

// Output:
// 2


#include <iostream>
#include <queue>
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

// Build tree from level order
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

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

// Find LCA
Node* findLCA(Node* root, int p, int q) {
    // If tree is empty
    if (root == NULL)
        return NULL;

    // If current node is p or q
    if (root->data == p || root->data == q)
        return root;

    // Search left and right
    Node* left = findLCA(root->left, p, q);
    Node* right = findLCA(root->right, p, q);

    // One node found on each side
    if (left != NULL && right != NULL)
        return root;

    // Return whichever side has a node
    if (left != NULL)
        return left;

    return right;
}

int main() {
    int n;
    cin >> n;

    int arr[1000];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int p, q;
    cin >> p >> q;

    Node* root = buildTree(arr, n);

    Node* ans = findLCA(root, p, q);

    if (ans != NULL)
        cout << ans->data;
    else
        cout << -1;

    return 0;
}