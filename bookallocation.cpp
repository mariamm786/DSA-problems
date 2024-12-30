#include <iostream>
#include <vector>
using namespace std;

// Function to check if a given maximum number of pages can be allocated
bool isValid(vector<int>&arr, int n, int m, int maxallowedpages) {
    int students = 1; // Start with one student
    int pages = 0;

    for (int i = 0; i < n; i++) {
        // If a single book has more pages than maxallowedpages, return false
        if (arr[i] > maxallowedpages) {
            return false;
        }

        // If adding this book exceeds maxallowedpages, allocate to a new student
        if (pages + arr[i] > maxallowedpages) {
            students++;
            pages = arr[i]; // Start the new student's allocation
            // If students exceed m, return false
            if (students > m) {
                return false;
            }
        } else {
            // Otherwise, add this book's pages to the current student's allocation
            pages += arr[i];
        }
    }
    return true; // Allocation is valid
}

// Main function to find the minimum number of pages
int allocatebooks(vector<int>& arr, int n, int m) {
    // If there are more students than books, allocation is not possible
    if (m > n) {
        return -1;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    int ans = -1;
    int st = 0, end = sum;

    while (st <= end) {
        int mid = st + (end - st) / 2;
        if (isValid(arr, n, m, mid)) {
            ans = mid;      // Update answer
            end = mid - 1;  // Try for a smaller maximum
        } else {
            st = mid + 1;   // Try for a larger maximum
        }
    }

    return ans;
}

int main() {
   vector<int> arr = {2, 1, 3, 4};
    int n = 4, m = 2;
    cout << allocatebooks(arr, n, m); // Output: 5
    return 0;
}
