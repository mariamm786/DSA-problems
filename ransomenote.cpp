#include <iostream>         // For input and output (optional here)
#include <string>           // For std::string
#include <unordered_map>    // For std::unordered_map

using namespace std;        // Avoids prefixing std:: for every identifier

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;

        // Count characters in ransomNote
        for (char str : ransomNote) {
            map[str]++;
        }

        // Process characters in magazine
        for (char mag : magazine) {
            if (map.find(mag) != map.end()) {
                map[mag]--;
                if (map[mag] == 0) {
                    map.erase(mag);
                }
            }
        }

        // If map is empty, all characters in ransomNote were found in magazine
        return map.empty();
    }
};

int main() {
    Solution solution;
    string ransomNote = "aa";
    string magazine = "aab";
    cout << (solution.canConstruct(ransomNote, magazine) ? "True" : "False") << endl;
    return 0;
}
