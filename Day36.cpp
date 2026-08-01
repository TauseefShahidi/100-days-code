// Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of elements to enqueue)
// - Second line: n space-separated integers
// - Third line: integer m (number of dequeue operations)

// Output:
// - Print queue elements from front to rear after operations, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 30 40 50 10 20

// Explanation:
// Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order


#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int q[100];

    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }

    int m;
    cin >> m;

    m = m % n;

    // Print after circular dequeue
    for (int i = m; i < n; i++)
        cout << q[i] << " ";

    for (int i = 0; i < m; i++)
        cout << q[i] << " ";

    return 0;
}
