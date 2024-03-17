/*
There are 8 prison cells in a row and each cell is either occupied or vacant.

Each day, whether the cell is occupied or vacant changes according to the following rules:

If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
Otherwise, it becomes vacant.
Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.

You are given an integer array cells where cells[i] == 1 if the ith cell is occupied and cells[i] == 0 if the ith cell is vacant, and you are given an integer n.

Return the state of the prison after n days (i.e., n such changes described above).



Example 1:

Input: cells = [0,1,0,1,1,0,0,1], n = 7
Output: [0,0,1,1,0,0,0,0]
Explanation: The following table summarizes the state of the prison on each day:
Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]
Example 2:

Input: cells = [1,0,0,1,0,0,1,0], n = 1000000000
Output: [0,0,1,1,1,1,1,0]


Constraints:

cells.length == 8
cells[i] is either 0 or 1.
1 <= n <= 109
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        unordered_map<string, int> seen;

        for (int i = 0; i < n; ++i) {
            string cellState(cells.begin(), cells.end());

            if (seen.find(cellState) != seen.end()) {
                int cycleStart = seen[cellState];
                int cycleLength = i - cycleStart;
                int remainingDays = (n - cycleStart) % cycleLength;
                return prisonAfterNDays(cells, remainingDays);
            } else {
                seen[cellState] = i;
                vector<int> next(cells.size(), 0);

                for (int j = 1; j < cells.size() - 1; ++j) {
                    next[j] = cells[j - 1] == cells[j + 1] ? 1 : 0;
                }

                cells = next;
            }
        }

        return cells;
    }
};

int main() {
    Solution solution;
    vector<int> cells1 = {0, 1, 0, 1, 1, 0, 0, 1};
    int n1 = 7;
    vector<int> result1 = solution.prisonAfterNDays(cells1, n1);
    cout << "Example 1: ";
    for (int cell : result1) {
        cout << cell << " ";
    }
    cout << endl;

    vector<int> cells2 = {1, 0, 0, 1, 0, 0, 1, 0};
    int n2 = 1000000000;
    vector<int> result2 = solution.prisonAfterNDays(cells2, n2);
    cout << "Example 2: ";
    for (int cell : result2) {
        cout << cell << " ";
    }
    cout << endl;

    return 0;
}
