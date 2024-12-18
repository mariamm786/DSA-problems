#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0; // Handle edge case: empty array
        }

        int unique = 1; // Pointer to track the position of the next unique element

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) { 
                // If a new unique element is found
                nums[unique] = nums[i]; // Place it in the next position
                unique++; // Increment the unique count
            }
        }

        return unique; // Return the number of unique elements
    }
};

int main(){
    // Create an instance of the Solution class
    Solution sol;

    // Example vector to test the function
    vector<int> nums = {1, 1, 2};

    // Call the function on the Solution object and store the result
    int uniqueCount = sol.removeDuplicates(nums);

    // Output the result
    cout << "Number of unique elements: " << uniqueCount << endl;

    // Output the modified array with unique elements
    cout << "Modified array: ";
    for (int i = 0; i < uniqueCount; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
