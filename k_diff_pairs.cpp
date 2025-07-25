class Solution {
    public:
        int findPairs(vector<int>& nums, int k) {
            if (k < 0) return 0; // Absolute difference can't be negative
    
            unordered_map<int, int> freq;
            
            // Step 1: Build frequency map
            for (int num : nums) {
                freq[num]++;
            }
    
            int count = 0;
    
            // Step 2: Iterate over map (not array)
            for (auto& [num, occ] : freq) {
                if (k == 0) {
                    // Case 1: k == 0 → check for duplicates
                    if (occ > 1) count++;
                } else {
                    // Case 2: k > 0 → check if num + k exists
                    if (freq.find(num + k) != freq.end()) {
                        count++;
                    }
                }
            }
    
            return count;
        }
    };
    