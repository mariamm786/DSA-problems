#include <iostream>
#include <string>
#include <algorithm> // For std::reverse

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.length();

        // Reverse the entire string
        reverse(s.begin(), s.end());

        for (int i = 0; i < n; i++) {
            string word = "";

            // Extract each word
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            // Reverse the extracted word
            reverse(word.begin(), word.end());

            // Add to the result string with a space
            if (word.length() > 0) {
                ans += " " + word;
            }
        }

        // Remove the leading space by returning substr(1)
        return ans.substr(1);
    }
};

int main() {
    // Test case
    Solution sol;
    string input = "  hello world  ";
    string result = sol.reverseWords(input);

    // Print the output
    cout << "Reversed Words: \"" << result << "\"" << endl;

    return 0;
}
