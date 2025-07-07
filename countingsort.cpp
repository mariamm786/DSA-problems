#include <iostream>
#include <climits>
using namespace std;

void countSort(int arr[], int n) {
    int freq[100000] = {0}; 
    int minVal = INT_MAX, maxVal = INT_MIN;

    // Find min and max values
    for (int i = 0; i < n; i++) {
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);  
    }

    // 1st step - O(n)
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // 2nd step - O(range) = max - min(use range here for loop)
    int j = 0;
    for (int i = minVal; i <= maxVal; i++) {
        while (freq[i] > 0) {
            arr[j++] = i;//the index value of the frequence array is the value of the original array
            freq[i]--;
        }
    }
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    countSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
