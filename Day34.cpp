// Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

// Input:
// - Postfix expression with operands and operators

// Output:
// - Print the integer result

// Example:
// Input:
// 2 3 1 * + 9 -

// Output:
// -4

// Explanation:
// Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.

#include <iostream>
#include <sstream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void push(Node* &top, int x) {
    Node* temp = new Node;
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop(Node* &top) {
    int x = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return x;
}

int main() {
    string expr;
    getline(cin, expr);

    stringstream ss(expr);
    string token;

    Node* top = NULL;

    while (ss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
            push(top, stoi(token));
        } else {
            int b = pop(top);
            int a = pop(top);

            if (token == "+")
                push(top, a + b);
            else if (token == "-")
                push(top, a - b);
            else if (token == "*")
                push(top, a * b);
            else if (token == "/")
                push(top, a / b);
        }
    }

    cout << pop(top);

    return 0;
}