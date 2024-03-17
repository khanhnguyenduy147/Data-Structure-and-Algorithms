/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]


Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.


Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (numMap.find(complement) != numMap.end()) {
                result.push_back(numMap[complement]);
                result.push_back(i);
                break;
            }
            numMap[nums[i]] = i;
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = solution.twoSum(nums1, target1);
    cout << "Example 1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = solution.twoSum(nums2, target2);
    cout << "Example 2: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> result3 = solution.twoSum(nums3, target3);
    cout << "Example 3: ";
    for (int num : result3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
