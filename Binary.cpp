#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
 public:
  string addBinary(string s1, string s2) {
    int i = s1.size() - 1, j = s2.size() - 1, carry = 0;
    string str = "";
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += s1[i--] - '0';
        if (j >= 0) sum += s2[j--] - '0';
        carry = sum / 2;
        str += to_string(sum % 2);
    }
    reverse(str.begin(), str.end());
    return str;
  }
};

int main() {
  Solution solution;
  string s1 = "1010", s2 = "1011";
  cout << "Result: " << solution.addBinary(s1, s2) << endl;
  return 0;
}
