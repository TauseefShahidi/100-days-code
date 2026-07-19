// Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print the merged linked list elements, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 35 45

// Output:
// 10 15 20 25 30 35 40 45 50

// Explanation:
// Compare nodes of both lists, append smaller to result, continue until all nodes are merged.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createList(int n) {
    Node *head = NULL, *temp = NULL;

    for (int i = 0; i < n; i++) {
        Node* newNode = new Node;
        cin >> newNode->data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

int main() {
    int n, m;
    cin >> n;
    Node* head1 = createList(n);

    cin >> m;
    Node* head2 = createList(m);

    Node *p1 = head1, *p2 = head2;

    while (p1 != NULL && p2 != NULL) {
        if (p1->data < p2->data) {
            cout << p1->data << " ";
            p1 = p1->next;
        } else {
            cout << p2->data << " ";
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        cout << p1->data << " ";
        p1 = p1->next;
    }

    while (p2 != NULL) {
        cout << p2->data << " ";
        p2 = p2->next;
    }

    return 0;
}