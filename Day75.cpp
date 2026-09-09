// Day 75 - Question 1: Largest Subarray with Zero Sum
// Close
// Problem Statement
// Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

// Input Format
// An integer array arr[].

// Output Format
// Print the length of the longest subarray with sum equal to zero.

// Sample Input
// 15 -2 2 -8 1 7 10 23

// Sample Output
// 5

// Explanation
// The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> firstIndex;

    int sum = 0;
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // If sum is 0, subarray starts from index 0
        if (sum == 0) {
            maxLength = i + 1;
        }

        // If this prefix sum appeared before
        if (firstIndex.find(sum) != firstIndex.end()) {
            maxLength = max(maxLength, i - firstIndex[sum]);
        } else {
            // Store the first occurrence
            firstIndex[sum] = i;
        }
    }

    cout << maxLength;

    return 0;
}