/*
An integer x is a good if after rotating each digit individually by 180 degrees, we get a valid number that is different from x. Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. For example:

0, 1, and 8 rotate to themselves,
2 and 5 rotate to each other (in this case they are rotated in a different direction, in other words, 2 or 5 gets mirrored),
6 and 9 rotate to each other, and
the rest of the numbers do not rotate to any other number and become invalid.
Given an integer n, return the number of good integers in the range [1, n].



Example 1:

Input: n = 10
Output: 4
Explanation: There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
Example 2:

Input: n = 1
Output: 0
Example 3:

Input: n = 2
Output: 1


Constraints:

1 <= n <= 104
*/
#include <iostream>

using namespace std;

class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;
        for (int i = 1; i <= n; ++i) {
            if (isGood(i))
                ++count;
        }
        return count;
    }

private:
    bool isGood(int num) {
        bool valid = false;
        while (num > 0) {
            int digit = num % 10;
            if (digit == 3 || digit == 4 || digit == 7)
                return false;
            if (digit == 2 || digit == 5 || digit == 6 || digit == 9)
                valid = true;
            num /= 10;
        }
        return valid;
    }
};

int main() {
    Solution solution;

    // Example usage
    cout << "Number of good integers up to 10: " << solution.rotatedDigits(10) << endl;
    cout << "Number of good integers up to 1: " << solution.rotatedDigits(1) << endl;
    cout << "Number of good integers up to 2: " << solution.rotatedDigits(2) << endl;

    return 0;
}
