// Problem: Given an array of integers, find two elements whose sum is closest to zero.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the pair of elements whose sum is closest to zero

// Example:
// Input:
// 5
// 1 60 -10 70 -80

// Output:
// -10 1

// Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.

#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[100];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int a = arr[0], b = arr[1];
    int minSum = abs(arr[0] + arr[1]);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(arr[i] + arr[j]) < minSum) {
                minSum = abs(arr[i] + arr[j]);
                a = arr[i];
                b = arr[j];
            }
        }
    }

    cout << a << " " << b;

    return 0;
}