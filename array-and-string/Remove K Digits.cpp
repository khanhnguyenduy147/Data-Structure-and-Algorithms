/*
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.



Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.


Constraints:

1 <= k <= num.length <= 105
num consists of only digits.
num does not have any leading zeros except for the zero itself.
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        // If k is equal to the length of num, return "0"
        if (k == num.length()) {
            return "0";
        }

        string result = "";
        int n = num.length();
        int keep = n - k; // Number of digits to keep

        for (char digit : num) {
            // While there are still digits to be removed and the current digit is smaller than the last digit in result
            while (k > 0 && !result.empty() && result.back() > digit) {
                result.pop_back(); // Remove the last digit from result
                k--;
            }
            result.push_back(digit); // Add the current digit to result
        }

        // Remove any remaining digits to be removed from the end of result
        result.resize(keep);

        // Remove leading zeros
        int leadingZeros = 0;
        while (leadingZeros < result.length() && result[leadingZeros] == '0') {
            leadingZeros++;
        }
        result = result.substr(leadingZeros);

        // If result is empty, return "0"
        if (result.empty()) {
            return "0";
        }

        return result;
    }
};

int main(){
    Solution solution;
    //Test case 1
    string num1 = "1432219";
    string result1;
    result1 = solution.removeKdigits(num1, 3);
    cout << "Example 1: " << result1 << endl;

    //Test case 2
    string num2 = "10200";
    string result2;
    result2 = solution.removeKdigits(num2, 1);
    cout << "Example 2: " << result2 << endl;

    //Test case 3
    string num3 = "10";
    string result3;
    result3 = solution.removeKdigits(num3, 2);
    cout << "Example 3: " << result3 << endl;

    return 0;
}
