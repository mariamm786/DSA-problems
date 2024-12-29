class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int lp = 0, rp = height.size() - 1; // Correct initialization

        while (lp < rp) {
            int w = rp - lp;                 // Width between pointers
            int ht = min(height[lp], height[rp]); // Height is the smaller of the two
            int currWater = w * ht;         // Calculate the current water area
            maxWater = max(maxWater, currWater); // Update max water area if current is larger

            // Move the pointer pointing to the shorter line
            if (height[lp] < height[rp]) {
                lp++;
            } else {
                rp--;  // Correctly move the right pointer
            }
        }

        return maxWater;
    }
};
