class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
       unordered_map<int,int>freq;
       int ans=0;
       for(int val : nums){
        freq[val]++;
       } 
       for(auto & [num,count]:freq){
        if(count ==2){
            ans = ans ^ num;
        }
       }
       return ans;
    }
};