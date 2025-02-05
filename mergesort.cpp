#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int si, int mid, int ei) {
    vector<int> temp;
    int i = si, j = mid + 1;

    while (i <= mid && j <= ei) {
        if (arr[i] < arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    // Copy remaining elements
    while (i <= mid) {
        temp.push_back(arr[i++]);
    }
    while (j <= ei) {
        temp.push_back(arr[j++]);
    }

    // Copy temp array back to original
    for (int idx = si, x = 0; idx <= ei; idx++, x++) {
        arr[idx] = temp[x];
    }
}

void mergesort(vector<int>& arr, int si, int ei) {
    if (si >= ei) {
        return;
    }
    int mid = si + (ei - si) / 2;
    mergesort(arr, si, mid);
    mergesort(arr, mid + 1, ei);
    merge(arr, si, mid, ei); // conquer
}

int main() {
    vector<int> arr = {5, 3, 8, 6, 2, 7, 4, 1};
    int n = arr.size();

    cout << "Original Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    mergesort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
