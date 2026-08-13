// Problem: Count Leaf Nodes

// Implement the solution for this problem.

// Input:
// - Input specifications

// Output:
// - Output specifications

#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < n) {
        Node* curr = q.front();
        q.pop();

        if (i < n && arr[i] != -1) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

int countLeaf(Node* root) {
    if (root == NULL)
        return 0;

    // Leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeaf(root->left) + countLeaf(root->right);
}

int main() {
    int n;
    cin >> n;

    int arr[1000];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Node* root = buildTree(arr, n);

    cout << countLeaf(root);

    return 0;
}