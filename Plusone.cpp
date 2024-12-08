class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Iterate from the last digit to the first
        for (int i = n - 1; i >= 0; i--) {
            digits[i]++;  // Increment the digit
            if (digits[i] < 10) {
                return digits;  // No carry, return result
            }
            digits[i] = 0;  // Set current digit to 0 if there's a carry
        }

        // If all digits are 9, add a leading 1 (e.g., [9, 9, 9] -> [1, 0, 0, 0])
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
