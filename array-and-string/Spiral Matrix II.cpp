/*
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.



Example 1:


Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Example 2:

Input: n = 1
Output: [[1]]


Constraints:

1 <= n <= 20
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        int num = 1;

        while (num <= n * n) {
            // Traverse from left to right
            for (int i = left; i <= right; ++i)
                matrix[top][i] = num++;
            top++;

            // Traverse from top to bottom
            for (int i = top; i <= bottom; ++i)
                matrix[i][right] = num++;
            right--;

            // Traverse from right to left
            for (int i = right; i >= left; --i)
                matrix[bottom][i] = num++;
            bottom--;

            // Traverse from bottom to top
            for (int i = bottom; i >= top; --i)
                matrix[i][left] = num++;
            left++;
        }

        return matrix;
    }
};

int main() {
    Solution solution;

    int n = 3; // Example 1
    vector<vector<int>> result1 = solution.generateMatrix(n);
    cout << "Example 1 Output:" << endl;
    for (const auto& row : result1) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    n = 1; // Example 2
    vector<vector<int>> result2 = solution.generateMatrix(n);
    cout << "Example 2 Output:" << endl;
    for (const auto& row : result2) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
