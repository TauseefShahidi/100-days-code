// Day 73 - Question 1: First Non-Repeating Character
// Close
// Problem Statement
// Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.

// Input Format
// A single string s.

// Output Format
// Print the first non-repeating character or '$' if none exists.

// Sample Input
// geeksforgeeks

// Sample Output
// f

// Explanation
// The character 'f' occurs only once in the string and appears before any other non-repeating character.

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int freq[26] = {0};

    // Count frequency of each character
    for (char ch : s) {
        freq[ch - 'a']++;
    }

    // Find the first character with frequency 1
    for (char ch : s) {
        if (freq[ch - 'a'] == 1) {
            cout << ch;
            return 0;
        }
    }

    cout << '$';

    return 0;
}