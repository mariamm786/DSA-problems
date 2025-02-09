class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string,vector<string>>groups;
            vector<vector<string>>ans;
            //char myarray;
            sort(strs.begin(),strs.end());
    
            for( string s : strs){
                string stringcopied = s;
                sort(stringcopied.begin(),stringcopied.end());
                groups[stringcopied].push_back(s);
            }
    
            for(auto& group : groups){
          ans.push_back(group.second);
            }
            
       return ans;
            
        }
    };