class Solution {
public:
    void sortColors(vector<int>& nums) {
       int n = nums.size();
       int countzero=0,countone=0,counttwo=0;
       for(int i=0;i<n;i++){
        if(nums[i]==0){
            countzero++;
        }else if (nums[i] == 1){
            countone++;
        }else{
            counttwo++;
        }
       }
       //over writing 
       int idx;
       idx=0;
       for(int i=0;i<countzero;i++){
         nums[idx++]=0;
       }
       for(int i=0;i<countone;i++){
        nums[idx++]=1;
       }
       for(int i=0;i<counttwo;i++){
        nums[idx++]=2;
       }

    }
    //return nums;
};