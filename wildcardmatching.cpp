class Solution {
    public:
    
    bool solvemem(string& str, string& pattern, int i, int j,vector<vector<int>>&dp) {
        // Base cases
        if (i < 0 && j < 0) {
            return true;
        }
        if (i >= 0 && j < 0) {
            return false;
        }
        if (i < 0 && j >= 0) {
            for (int k = 0; k <= j; k++) {
                if (pattern[k] != '*') {
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
       bool result;
        // Match logic
        if (str[i] == pattern[j] || pattern[j] == '?') {
            result= solvemem(str, pattern, i - 1, j - 1,dp);
        } else if (pattern[j] == '*') {
            result= solvemem(str, pattern, i - 1, j,dp) || solvemem(str, pattern, i, j - 1,dp);
        } else {
            return  result =false;
        }
        return dp[i][j] = result;
    }
    
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.length(),vector<int>(p.length(),-1));
        return solvemem(s, p, s.length() - 1, p.length() - 1,dp);
    }
    
    };
    