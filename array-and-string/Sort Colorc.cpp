/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.



Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]


Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1, curr = 0;

        while (curr <= right) {
            if (nums[curr] == 0) {
                swap(nums[left++], nums[curr++]);
            } else if (nums[curr] == 2) {
                swap(nums[right--], nums[curr]);
            } else {
                curr++;
            }
        }
    }
};

int main(){
    Solution solution;
    //Test case 1
    vector<int> nums1 = {2,0,2,1,1,0};
    solution.sortColors(nums1);
    for(auto a : nums1) {
        cout << a << " ";
    }
    cout << endl;
    //Test case 2
    vector<int> nums2 = {2,0,1};
    solution.sortColors(nums2);
    for(auto a : nums2) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}
