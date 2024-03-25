/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.



Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Define the four directions
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Queue to store coordinates of rotten oranges
        queue<pair<int, int>> rotten;

        // Count of fresh oranges
        int freshCount = 0;

        // Initialize the queue with rotten oranges and count fresh oranges
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2)
                    rotten.push({i, j});
                else if (grid[i][j] == 1)
                    freshCount++;
            }
        }

        int minutes = 0;

        // BFS traversal to rot adjacent fresh oranges
        while (!rotten.empty() && freshCount > 0) {
            int size = rotten.size();

            for (int i = 0; i < size; ++i) {
                auto x = rotten.front().first;
                auto y = rotten.front().second;
                rotten.pop();

                // Check all four directions
                for (auto& dir : directions) {
                    int nx = x + dir.first;
                    int ny = y + dir.second;

                    // Check if new coordinates are within bounds and the cell has fresh orange
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        // Mark the fresh orange as rotten
                        grid[nx][ny] = 2;
                        // Add the newly rotten orange to the queue
                        rotten.push({nx, ny});
                        // Decrease the count of fresh oranges
                        freshCount--;
                    }
                }
            }
            // Increment the minute after rotting oranges at this level
            minutes++;
        }

        // If there are still fresh oranges left, return -1, otherwise return the number of minutes
        return (freshCount == 0) ? minutes : -1;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<vector<int>> grid1 = {{2,1,1},{1,1,0},{0,1,1}};
    cout << "Example 1 Output: " << solution.orangesRotting(grid1) << endl;

    // Example 2
    vector<vector<int>> grid2 = {{2,1,1},{0,1,1},{1,0,1}};
    cout << "Example 2 Output: " << solution.orangesRotting(grid2) << endl;

    // Example 3
    vector<vector<int>> grid3 = {{0,2}};
    cout << "Example 3 Output: " << solution.orangesRotting(grid3) << endl;

    return 0;
}
