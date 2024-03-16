/*
Given an integer array nums, handle multiple queries of the following types:

Update the value of an element in nums.
Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
void update(int index, int val) Updates the value of nums[index] to be val.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).


Example 1:

Input
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
Output
[null, 9, null, 8]

Explanation
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
numArray.update(1, 2);   // nums = [1, 2, 5]
numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8


Constraints:

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
0 <= index < nums.length
-100 <= val <= 100
0 <= left <= right < nums.length
At most 3 * 104 calls will be made to update and sumRange.
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class NumArray {
private:
    vector<int> prefixSum;
public:
    NumArray(vector<int> nums) {
        int n = nums.size();
        prefixSum.resize(n + 1, 0);
        for(int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
    }
    void update(int index, int val) {
        int diff = val - (prefixSum[index + 1] - prefixSum[index]);
        for(int i = index + 1; i < prefixSum.size(); ++i) {
            prefixSum[i] += diff;
        }
    }
    int sumRange(int left, int right) {
        return prefixSum[right + 1] - prefixSum[left];
    }
};
int main(){
    //Test case
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    NumArray numArray(nums);

    cout << "Sum Range [1, 3]: " << numArray.sumRange(1, 3) << endl;

    numArray.update(2, 10);
    cout << "Sum Range [2, 4] after update: " << numArray.sumRange(2, 4) << endl;

    return 0;
}
