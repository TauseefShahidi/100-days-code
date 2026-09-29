// Day 85 - Question 1: Implement Merge Sort
// Close
// Problem: Implement Merge Sort - Implement the algorithm.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the sorted array or search result

// Example:
// Input:
// 5
// 64 34 25 12 22

// Output:
// 12 22 25 34 64

#include <iostream>
using namespace std;

// Merge two sorted parts
void merge(int arr[], int low, int mid, int high) {
    int temp[100];
    int i = low;
    int j = mid + 1;
    int k = low;

    // Compare and store elements
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        }
        else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from left part
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Copy remaining elements from right part
    while (j <= high) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy back to original array
    for (int p = low; p <= high; p++) {
        arr[p] = temp[p];
    }
}

// Merge Sort
void mergeSort(int arr[], int low, int high) {
    if (low >= high) {
        return;
    }

    int mid = low + (high - low) / 2;

    // Sort left half
    mergeSort(arr, low, mid);

    // Sort right half
    mergeSort(arr, mid + 1, high);

    // Merge both halves
    merge(arr, low, mid, high);
}

int main() {
    int n;
    cin >> n;

    int arr[100];

    // Input
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Merge Sort
    mergeSort(arr, 0, n - 1);

    // Output
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}