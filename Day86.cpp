// 

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int low = 0;
    int high = n;
    int answer = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (mid <= n / mid) {
            // mid * mid <= n
            answer = mid;
            low = mid + 1;
        }
        else {
            // mid * mid > n
            high = mid - 1;
        }
    }

    cout << answer;

    return 0;
}