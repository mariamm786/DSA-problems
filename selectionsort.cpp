#include <iostream>
using namespace std;

int main() {
    // Example array size
    int n = 5;
    int arr[5];

    // Input elements
    cout << "Enter 5 elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Selection Sort Algorithm
    for (int i = 0; i < n - 1; i++) {
        // Assume the minimum is at position i
        int minIndex = i;

        // Find the index of the smallest element in the remaining array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element of unsorted part
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    // Display the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
