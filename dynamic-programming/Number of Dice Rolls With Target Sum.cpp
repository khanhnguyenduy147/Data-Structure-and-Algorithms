/*
You have n dice, and each dice has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.



Example 1:

Input: n = 1, k = 6, target = 3
Output: 1
Explanation: You throw one die with 6 faces.
There is only one way to get a sum of 3.
Example 2:

Input: n = 2, k = 6, target = 7
Output: 6
Explanation: You throw two dice, each with 6 faces.
There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
Example 3:

Input: n = 30, k = 30, target = 500
Output: 222616187
Explanation: The answer must be returned modulo 109 + 7.


Constraints:

1 <= n, k <= 30
1 <= target <= 1000
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                for (int face = 1; face <= k; ++face) {
                    if (j - face >= 0) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - face]) % MOD;
                    }
                }
            }
        }

        return dp[n][target];
    }
};

int main() {
    Solution sol;

    // Test cases
    int n1 = 1, k1 = 6, target1 = 3;
    cout << "Output for Test Case 1: " << sol.numRollsToTarget(n1, k1, target1) << endl;

    int n2 = 2, k2 = 6, target2 = 7;
    cout << "Output for Test Case 2: " << sol.numRollsToTarget(n2, k2, target2) << endl;

    int n3 = 30, k3 = 30, target3 = 500;
    cout << "Output for Test Case 3: " << sol.numRollsToTarget(n3, k3, target3) << endl;

    return 0;
}
