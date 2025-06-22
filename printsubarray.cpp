#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "All subarrays of the array are:\n";

    // Start point of subarray
    for (int i = 0; i < n; i++) {
        // End point of subarray
        for (int j = i; j < n; j++) {
            // Print elements between i and j
            for (int k = i; k <= j; k++) {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}