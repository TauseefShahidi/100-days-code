// Day 72 - Question 1: First Repeated Character
// Close
// Problem Statement
// Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.

// Input Format
// A single string s.

// Output Format
// Print the first repeated character. If no character is repeated, print -1.

// Sample Input
// geeksforgeeks

// Sample Output
// e

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    bool seen[26] = {false};

    for (char ch : s) {
        int index = ch - 'a';

        if (seen[index]) {
            cout << ch;
            return 0;
        }

        seen[index] = true;
    }

    cout << -1;

    return 0;
}