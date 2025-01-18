#include<iostrem>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int tar) {
        unordered_map<int,int>m;
        vector<int>ans;
        int n = arr.size();
        for(int i=0;i<n;i++){
            int first = arr[i];
            int second = tar-first;
            if(m.find(second) != m.end()){
                ans.push_back(i);
                ans.push_back(m[second]);
            }
            m[first] = i;
        }
        return ans;
    }
};