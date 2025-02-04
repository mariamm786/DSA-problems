#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        // Check for zero inputs
        if (num1 == "0" || num2 == "0") return "0";

        int n = num1.size();
        int m = num2.size();
        string result(n + m, '0'); // Result can be at most n + m digits long

        // Multiply each digit of num1 and num2
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int product = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0');
                result[i + j + 1] = product % 10 + '0';  // Store the last digit
                result[i + j] += product / 10;  // Add carry to the next position
            }
        }

        // Remove leading zeros
        int i = 0;
        while (i < result.size() && result[i] == '0') i++;
        return result.substr(i);
    }
};

int main() {
    Solution solution;
    string num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    
    string product = solution.multiply(num1, num2);
    cout << "Product: " << product << endl;
    return 0;
}