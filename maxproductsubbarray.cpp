#include <vector>
#include <algorithm> // for max and min functions
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        int max_product = nums[0];
        int current_max = nums[0];
        int current_min = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            int temp_max = current_max; // Save the current max before updating
            current_max = max({nums[i], current_max * nums[i], current_min * nums[i]});
            current_min = min({nums[i], temp_max * nums[i], current_min * nums[i]});
            max_product = max(max_product, current_max);
        }

        return max_product;
    }
};
