/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.



Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.


Constraints:

2 <= cost.length <= 1000
0 <= cost[i] <= 999
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);

        //Base case
        dp[0] = cost[0];
        dp[1] = cost[1];

        //Dynamic programming to fill dp array
        for(int i = 2; i < n ; ++i) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        return min(dp[n - 1], dp[n - 2]);
    }
};

int main(){
    //Test case
    vector<int> cost1 = {10, 15, 20};
    Solution solution1;
    cout << "Minimun cost for cost1: " << solution1.minCostClimbingStairs(cost1) << endl;

    vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    Solution solution2;
    cout << "Minimun cost for cost2: " << solution2.minCostClimbingStairs(cost2) << endl;

    return 0;
}
