class Solution {
public:
    vector<string> findWords(vector<string>& words) {
       unordered_map<char,int>map;
        string s1="qwertyuiop";
        string s2="asdfghjkl";
        string s3="zxcvbnm";

        for(auto c : s1){
            map[c]=1;
        }
        for(auto c:s2){
            map[c]=2;
        }
        for(auto c: s3){
            map[c]=3;
        }
        vector<int>ans;
        for(auto word : words){
            bool flag = true;
            int row = map[tolower[word[0]]];
            for(auto c : word){
                if (map[tolower(c)] != row){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans.push_back(word);
            }
        }
        return ans;
    }
};