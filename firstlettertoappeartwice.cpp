class Solution {
public:

char seentwice(const string &s){
unordered_set<char>seen;
for(char c : s){
    if(seen.find(c) != seen.end()){
        return c;
    }
    seen.insert(c);
}
 return '\0';
}
    char repeatedCharacter(string s) {
       
        return seentwice(s);
    }
};