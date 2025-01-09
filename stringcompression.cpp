class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int count =0;
        int n = word.length();
        for(int i=0;i<n;i++){
            char current = word[i];
            count =0;
            while(i<n && word[i] == current && count<9){
                count++;
                i++;
            }
            i--;
            comp+= to_string(count) + current;
            
        }
        return comp;
    }
};