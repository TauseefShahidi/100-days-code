// Problem Statement:
// Implement a Priority Queue using an array. An element with smaller value has higher priority.

// Supported Operations:
// - insert x
// - delete
// - peek

// Input Format:
// - First line contains integer N
// - Next N lines contain operations

// Output Format:
// - Print the deleted or peeked element
// - Print -1 if the queue is empty

// Example:
// Input:
// 5
// insert 30
// insert 10
// insert 20
// delete
// peek

// Output:
// 10
// 20

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    int pq[100];
    int size = 0;

    while (n--) {
        string op;
        cin >> op;

        if (op == "insert") {
            int x;
            cin >> x;
            pq[size++] = x;
        }
        else if (op == "delete") {
            if (size == 0) {
                cout << -1 << endl;
            } else {
                int minIndex = 0;
                for (int i = 1; i < size; i++) {
                    if (pq[i] < pq[minIndex])
                        minIndex = i;
                }

                cout << pq[minIndex] << endl;

                for (int i = minIndex; i < size - 1; i++)
                    pq[i] = pq[i + 1];

                size--;
            }
        }
        else if (op == "peek") {
            if (size == 0) {
                cout << -1 << endl;
            } else {
                int minValue = pq[0];
                for (int i = 1; i < size; i++) {
                    if (pq[i] < minValue)
                        minValue = pq[i];
                }

                cout << minValue << endl;
            }
        }
    }

    return 0;
}