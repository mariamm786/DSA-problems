class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            vector<int> ans;
            unordered_set<int> s;
            int expsum = 0; // Expected sum
            int actualsum = 0; // Actual sum
            int repeated, missing;
            int n = grid.size();
    
            // Calculate actual sum and find the repeated value
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    actualsum += grid[i][j];
                    if (s.find(grid[i][j]) != s.end()) { // Check if value is repeated
                        repeated = grid[i][j];
                    }
                    s.insert(grid[i][j]);
                }
            }
    
            // Calculate expected sum for numbers 1 to n^2
            expsum = (n * n * (n * n + 1)) / 2;
    
            // Missing value calculation
            missing = expsum + repeated - actualsum;
    
            // Add results to the answer vector
            ans.push_back(repeated);
            ans.push_back(missing);
    
            return ans;
        }
    };