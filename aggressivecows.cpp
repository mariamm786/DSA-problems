#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if it is possible to place 'k' cows with a minimum distance of 'dist'
bool isPossible(vector<int>& stalls, int k, int dist) {
    int count = 1; // Place the first cow
    int lastPosition = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPosition >= dist) {
            count++;
            lastPosition = stalls[i];
        }
        if (count >= k) {
            return true;
        }
    }
    return false;
}

// Function to find the largest minimum distance
int aggressiveCows(vector<int>& stalls, int k) {
    sort(stalls.begin(), stalls.end()); // Sort the stalls in ascending order

    int low = 1; // Minimum possible distance
    int high = stalls.back() - stalls.front(); // Maximum possible distance
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(stalls, k, mid)) {
            result = mid; // Update the result if placement is possible
            low = mid + 1; // Try for a larger distance
        } else {
            high = mid - 1; // Try for a smaller distance
        }
    }

    return result;
}

int main() {
    vector<int> stalls = {1, 2, 4, 8, 9};
    int k = 3;

    cout << "The largest minimum distance is: " << aggressiveCows(stalls, k) << endl;

    return 0;
}
