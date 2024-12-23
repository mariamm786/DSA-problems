class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int freq1,freq2=0;
         int ans1=0,ans2=0;

        

        for(int i=0;i<nums.size();i++){
           if(nums[i] == ans1){
            freq1++;
           }else if(nums[i] == ans2){
            freq2++;
           }else if(freq1 == 0){
            ans1= nums[i];
            freq1=1;
           }else if(freq2 == 0){
            ans2 = nums[i];
            freq2=1;
           }else{
            freq1--;
            freq2--;
           }
        }
        freq1= 0;
        freq2 = 0;
        for (int num : nums) {
            if (num == ans1) freq1++;
            else if (num == ans2) freq2++;
        }
        
        vector<int>total;
        if (freq1 > nums.size() / 3) total.push_back(ans1);
        if (freq2 > nums.size() / 3) total.push_back(ans2);
        
        return total;
    }
};