class Solution {
public:

int backtrack(int i,int currentsum,vector<int>& nums,int target){
    if(i == nums.size()){
        if(currentsum == target){
            return 1;
        }
        return 0;
    }
int ans=0;
    int add = backtrack(i+1,currentsum+nums[i],nums,target);
    int sub = backtrack(i+1,currentsum-nums[i],nums,target);
ans = add +sub;
return ans;
}
    int findTargetSumWays(vector<int>& nums, int target) {
         return backtrack(0,0,nums,target);
    }
};