/*
You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized.

Return that maximum distance to the closest person.



Example 1:


Input: seats = [1,0,0,0,1,0,1]
Output: 2
Explanation:
If Alex sits in the second open seat (i.e. seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.
Example 2:

Input: seats = [1,0,0,0]
Output: 3
Explanation:
If Alex sits in the last seat (i.e. seats[3]), the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.
Example 3:

Input: seats = [0,1]
Output: 1


Constraints:

2 <= seats.length <= 2 * 104
seats[i] is 0 or 1.
At least one seat is empty.
At least one seat is occupied.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int maxDistance = 0;

        // Calculate distance from the first seat to the first occupied seat
        int start = 0;
        while (start < n && seats[start] == 0)
            start++;
        maxDistance = max(maxDistance, start);

        // Calculate distance from the last seat to the last occupied seat
        int end = n - 1;
        while (end >= 0 && seats[end] == 0)
            end--;
        maxDistance = max(maxDistance, n - 1 - end);

        // Calculate maximum distance between two adjacent occupied seats
        int prevOccupied = -1;
        for (int i = 0; i < n; ++i) {
            if (seats[i] == 1) {
                if (prevOccupied != -1) {
                    int distance = (i - prevOccupied) / 2;
                    maxDistance = max(maxDistance, distance);
                }
                prevOccupied = i;
            }
        }

        return maxDistance;
    }
};

int main() {
    Solution solution;

    // Example usage
    vector<int> seats1 = {1,0,0,0,1,0,1};
    cout << "Example 1: " << solution.maxDistToClosest(seats1) << endl;

    vector<int> seats2 = {1,0,0,0};
    cout << "Example 2: " << solution.maxDistToClosest(seats2) << endl;

    vector<int> seats3 = {0,1};
    cout << "Example 3: " << solution.maxDistToClosest(seats3) << endl;

    return 0;
}
