class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int n = nums.size();
            int maxSum = INT_MIN;
    
            for (int start = 0; start < n; ++start) {
                for (int end = start; end < n; ++end) {
                    int currSum = 0;
                    for (int i = start; i <= end; ++i) {
                        currSum += nums[i];
                    }
                    maxSum = max(maxSum, currSum);
                }
            }
    
            return maxSum;
        }
    };