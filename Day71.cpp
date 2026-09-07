// Day 71 - Question 1: Hash Table Using Quadratic Probing
// Close
// Problem Statement
// Implement a hash table using quadratic probing with formula:

// h(k, i) = (h(k) + i*i) % m

// Input Format
// Same as previous.

// Output Format
// Result of SEARCH operations.

// Sample Input
// 7
// 4
// INSERT 49
// INSERT 56
// SEARCH 49
// SEARCH 15

// Sample Output
// FOUND
// NOT FOUND

// Explanation
// Collisions resolved using i² jumps.

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    int m;
    cin >> m;

    int n;
    cin >> n;

    vector<int> table(m, -1);

    string operation;
    int key;

    for (int i = 0; i < n; i++) {
        cin >> operation >> key;

        int index;

        if (operation == "INSERT") {
            bool inserted = false;

            for (int j = 0; j < m; j++) {
                index = (key % m + j * j) % m;

                if (table[index] == -1) {
                    table[index] = key;
                    inserted = true;
                    break;
                }
            }
        }

        else if (operation == "SEARCH") {
            bool found = false;

            for (int j = 0; j < m; j++) {
                index = (key % m + j * j) % m;

                if (table[index] == key) {
                    found = true;
                    break;
                }

                // If slot is empty, key cannot be further in this probe sequence
                if (table[index] == -1) {
                    break;
                }
            }

            if (found)
                cout << "FOUND\n";
            else
                cout << "NOT FOUND\n";
        }
    }

    return 0;
}