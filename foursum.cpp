class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            vector<vector<int>> sum;
            sort(nums.begin(), nums.end());
    
            if (nums.size() < 4) return sum;
    
            for (int i = 0; i < nums.size() - 3; i++) {
                if (i > 0 && nums[i] == nums[i - 1]) continue;
    
                for (int j = i + 1; j < nums.size() - 2; j++) {
                    if (j > i + 1 && nums[j] == nums[j - 1]) continue; 
    
                    int k = j + 1;
                    int l = nums.size() - 1;
    
                    while (k < l) {
                        long long total_sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
    
                        if (total_sum == target) {
                            sum.push_back({nums[i], nums[j], nums[k], nums[l]});
    
                            
                            while (k < l && nums[k] == nums[k + 1]) k++;
                            while (k < l && nums[l] == nums[l - 1]) l--;
    
                            k++;
                            l--;
                        } else if (total_sum < target) {
                            k++;
                        } else {
                            l--; 
                        }
                    }
                }
            }
            return sum;
        }
    };