// Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of nodes)
// - Second line: n space-separated integers (linked list elements)
// - Third line: integer key (element to be counted)

// Output:
// - Print the number of times the key appears in the linked list

// Example:
// Input:
// 6
// 10 20 30 20 40 20
// 20

// Output:
// 3

// Explanation:
// Traverse the linked list from head to end. Each time a node's data matches the given key, increment a counter. After traversal, print the final count.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    int n;
    cin >> n;

    Node *head = NULL, *temp = NULL;

    // Create linked list
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

    int key;
    cin >> key;

    int count = 0;
    temp = head;

    while (temp != NULL) {
        if (temp->data == key)
            count++;

        temp = temp->next;
    }

    cout << count;

    return 0;
}