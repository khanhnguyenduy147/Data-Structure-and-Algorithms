/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.



Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> result(m, vector<int>(n, -1));

        queue<pair<int, int>> q;

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                    result[i][j] = 0;
                }
            }
        }

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(const auto& dir : directions) {
                int dx = dir.first;
                int dy = dir.second;
                int nx = x + dx;
                int ny = y + dy;

                if(nx >= 0 && nx < m && ny >= 0 && ny < n && result[nx][ny] == -1){
                    result[nx][ny] = result[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return result;
    }
};
int main(){
    //Test case
    vector<vector<int>> mat1 = {{0,0,0},{0,1,0},{0,0,0}};
    Solution solution1;
    vector<vector<int>> result1 = solution1.updateMatrix(mat1);
    cout << "Result for mat1:" << endl;
    for (const auto& row : result1) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    vector<vector<int>> mat2 = {{0,0,0},{0,1,0},{1,1,1}};
    Solution solution2;
    vector<vector<int>> result2 = solution2.updateMatrix(mat2);
    cout << "Result for mat2:" << endl;
    for (const auto& row : result2) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
