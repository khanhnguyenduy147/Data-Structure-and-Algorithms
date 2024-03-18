/*
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.



Example 1:


Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
Example 2:


Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).
Example 3:


Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).


Constraints:

The number of nodes in the tree is in the range [1, 3000].
-100 <= Node.val <= 100
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int maxWidth = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 1});

        while (!q.empty()) {
            int size = q.size();
            unsigned long long left = q.front().second, right = left;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front().first;
                right = q.front().second;
                q.pop();
                if (node->left) q.push({node->left, right * 2});
                if (node->right) q.push({node->right, right * 2 + 1});
            }
            maxWidth = max(maxWidth, static_cast<int>(right - left + 1));
        }

        return maxWidth;
    }
};

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    Solution sol;
    int maxWidth = sol.widthOfBinaryTree(root);
    cout << "Maximum width of the binary tree: " << maxWidth << endl;

    // Remember to free memory to avoid memory leaks
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
