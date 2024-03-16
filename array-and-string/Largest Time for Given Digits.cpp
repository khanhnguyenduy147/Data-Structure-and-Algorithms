/*
Given an array arr of 4 digits, find the latest 24-hour time that can be made using each digit exactly once.

24-hour times are formatted as "HH:MM", where HH is between 00 and 23, and MM is between 00 and 59. The earliest 24-hour time is 00:00, and the latest is 23:59.

Return the latest 24-hour time in "HH:MM" format. If no valid time can be made, return an empty string.



Example 1:

Input: arr = [1,2,3,4]
Output: "23:41"
Explanation: The valid 24-hour times are "12:34", "12:43", "13:24", "13:42", "14:23", "14:32", "21:34", "21:43", "23:14", and "23:41". Of these times, "23:41" is the latest.
Example 2:

Input: arr = [5,5,5,5]
Output: ""
Explanation: There are no valid 24-hour times as "55:55" is not valid.


Constraints:

arr.length == 4
0 <= arr[i] <= 9
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        string result ="";
        do {
            string hour = to_string(arr[0]) + to_string(arr[1]);
            string minute = to_string(arr[2]) + to_string(arr[3]);
            if(hour < "24" && minute < "60") {
                string time = hour + ":" + minute;
                if(time > result){
                    result = time;
                }
            }
        } while(next_permutation(arr.begin(), arr.end()));
        return result;
    }
};
int main(){
    Solution solution;
    //Test case
    vector<int> arr1 = {1, 2, 3, 4};
    cout << "Example 1: " << solution.largestTimeFromDigits(arr1) << endl;

    vector<int> arr2 = {5, 5, 5, 5};
    cout << "Example 2: " << solution.largestTimeFromDigits(arr2) << endl;
    return 0;
}
