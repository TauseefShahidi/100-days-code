// Problem Statement:
// Implement a Queue using a linked list supporting enqueue and dequeue operations.

// Input Format:
// - First line contains integer N
// - Next N lines contain queue operations

// Output Format:
// - Print dequeued elements
// - Print -1 if dequeue is attempted on an empty queue

#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

// Enqueue
void enqueue(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;

    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

// Dequeue
void dequeue() {
    if (front == NULL) {
        cout << -1 << endl;
        return;
    }

    cout << front->data << endl;
    Node* temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    delete temp;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        string op;
        cin >> op;

        if (op == "enqueue") {
            int x;
            cin >> x;
            enqueue(x);
        }
        else if (op == "dequeue") {
            dequeue();
        }
    }

    return 0;
}