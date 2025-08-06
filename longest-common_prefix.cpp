class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string first = strs[0];
        string prefix = "";

        for (int i = 0; i < first.length(); ++i) {
            prefix += first[i];  // add one character to the prefix

            // check if all strings start with the current prefix
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[j].find(prefix) != 0) {  // prefix not at the start
                    return prefix.substr(0, prefix.length() - 1);  // remove last char
                }
            }
        }

        return prefix;
    }
};
