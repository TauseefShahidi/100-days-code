// Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer key

// Output:
// - Print the linked list elements after deletion, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 30

// Output:
// 10 20 40 50

// Explanation:
// Traverse list, find first node with key, remove it by adjusting previous node's next pointer.

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

    Node *curr = head, *prev = NULL;

    while (curr != NULL) {
        if (curr->data == key) {
            if (prev == NULL) {
                head = head->next;
            } else {
                prev->next = curr->next;
            }
            delete curr;
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    // Print updated list
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}