// Problem: Implement push and pop operations on a stack and verify stack operations.

// Input:
// - First line: integer n
// - Second line: n integers to push
// - Third line: integer m (number of pops)

// Output:
// - Print remaining stack elements from top to bottom

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 30 20 10

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int stack[100];
    int top = -1;

    // Push elements
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        top++;
        stack[top] = x;
    }

    int m;
    cin >> m;

    // Pop m elements
    while (m > 0 && top != -1) {
        top--;
        m--;
    }

    // Display remaining stack from top to bottom
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << " ";
    }

    return 0;
}