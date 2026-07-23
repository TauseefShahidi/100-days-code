// Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print value of intersection node or 'No Intersection'

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 30 40 50

// Output:
// 30

// Explanation:
// Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.




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

    Node* p1 = head1;
    bool found = false;

    while (p1 != NULL) {
        Node* p2 = head2;

        while (p2 != NULL) {
            if (p1->data == p2->data) {
                cout << p1->data;
                found = true;
                break;
            }
            p2 = p2->next;
        }

        if (found)
            break;

        p1 = p1->next;
    }

    if (!found)
        cout << "No Intersection";

    return 0;
}