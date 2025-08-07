class Solution {
public:
    int solvemem(int n,vector<int>&dp){
        if(n == 1){
            return 1;
        }
        if(n ==2){
        return 2;
        }
    if(dp[n] != -1){
        return dp[n];
    }
    int maxi=0;
    int ans=0;
     if (n > 2){
         ans = solvemem(n-1,dp) + solvemem(n-2,dp);

    }
    maxi= max(maxi,ans);
    dp[n] = maxi;
    return dp[n];

    }

    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return solvemem(n,dp);
    }
};