// Problem Statement:
// Implement a Min Heap using an array where the smallest element is always at the root.

// Supported Operations:
// - insert x
// - extractMin
// - peek

// Input Format:
// - First line contains integer N
// - Next N lines contain heap operations

// Output Format:
// - Print results of extractMin and peek
// - Print -1 if operation cannot be performed

// Example:
// Input:
// 6
// insert 40
// insert 10
// insert 30
// peek
// extractMin
// peek

// Output:
// 10
// 10
// 30

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> heap;

// Insert into Min Heap
void insert(int x) {
    heap.push_back(x);
    int i = heap.size() - 1;

    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] > heap[i]) {
            swap(heap[parent], heap[i]);
            i = parent;
        } else {
            break;
        }
    }
}

// Heapify after deletion
void heapify(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap.size() && heap[left] < heap[smallest])
        smallest = left;

    if (right < heap.size() && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapify(smallest);
    }
}

// Extract minimum element
void extractMin() {
    if (heap.empty()) {
        cout << -1 << endl;
        return;
    }

    cout << heap[0] << endl;

    heap[0] = heap.back();
    heap.pop_back();

    if (!heap.empty())
        heapify(0);
}

// Peek minimum element
void peek() {
    if (heap.empty())
        cout << -1 << endl;
    else
        cout << heap[0] << endl;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        string op;
        cin >> op;

        if (op == "insert") {
            int x;
            cin >> x;
            insert(x);
        }
        else if (op == "extractMin") {
            extractMin();
        }
        else if (op == "peek") {
            peek();
        }
    }

    return 0;
}