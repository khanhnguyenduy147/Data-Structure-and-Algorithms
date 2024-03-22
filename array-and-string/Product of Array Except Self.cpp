/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.



Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]


Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.


Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftProducts(n);
        vector<int> rightProducts(n);
        vector<int> result(n);

        leftProducts[0] = 1;
        for (int i = 1; i < n; ++i) {
            leftProducts[i] = leftProducts[i - 1] * nums[i - 1];
        }

        rightProducts[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i) {
            rightProducts[i] = rightProducts[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; ++i) {
            result[i] = leftProducts[i] * rightProducts[i];
        }

        return result;
    }
};

int main(){
    Solution solution;

    //Test case 1
    vector<int> num1 = {1,2,3,4};
    vector<int> result1 = solution.productExceptSelf(num1);
    for(auto p : result1) {
        cout << p << " ";
    }
    cout << endl;
    //Test case 2
    solution.productExceptSelf(num1);
    vector<int> num2 = {-1,1,0,-3,3};
    vector<int> result2 = solution.productExceptSelf(num2);
    for(auto p : result2) {
        cout << p << " ";
    }
    cout << endl;

    return 0;
}
