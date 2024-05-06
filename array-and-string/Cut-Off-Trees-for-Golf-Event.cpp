#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size();
        int n = forest[0].size();

        vector<tuple<int, int, int>> trees; // (height, row, col)

        // Collect all tree positions
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (forest[i][j] > 1) {
                    trees.emplace_back(forest[i][j], i, j);
                }
            }
        }

        // Sort trees by height
        sort(trees.begin(), trees.end());

        int steps = 0;
        int row = 0, col = 0;
        for (const auto& tree : trees) {
            int height, i, j;
            tie(height, i, j) = tree;
            int dist = bfs(forest, row, col, i, j);
            if (dist == -1) return -1; // Cannot reach the tree
            steps += dist;
            row = i;
            col = j;
        }

        return steps;
    }

private:
    int bfs(const vector<vector<int>>& forest, int sr, int sc, int tr, int tc) {
        int m = forest.size();
        int n = forest[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        visited[sr][sc] = true;

        vector<int> dr = {-1, 1, 0, 0}; // Directions: up, down, left, right
        vector<int> dc = {0, 0, -1, 1};

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; ++k) {
                auto front_pair = q.front();
                int r = front_pair.first;
                int c = front_pair.second;

                q.pop();

                if (r == tr && c == tc) return steps;

                for (int i = 0; i < 4; ++i) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] && forest[nr][nc] != 0) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
            ++steps;
        }

        return -1; // Cannot reach the target
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<vector<int>> forest1 = {{1,2,3},{0,0,4},{7,6,5}};
    cout << "Example 1 Output: " << solution.cutOffTree(forest1) << endl;

    // Example 2
    vector<vector<int>> forest2 = {{1,2,3},{0,0,0},{7,6,5}};
    cout << "Example 2 Output: " << solution.cutOffTree(forest2) << endl;

    // Example 3
    vector<vector<int>> forest3 = {{2,3,4},{0,0,5},{8,7,6}};
    cout << "Example 3 Output: " << solution.cutOffTree(forest3) << endl;

    return 0;
}
