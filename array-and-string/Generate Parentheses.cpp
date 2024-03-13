/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.



Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]


Constraints:

1 <= n <= 8
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void generateParenthesisHelper(int openCount, int closeCount, int n, string current, vector<string>& result){
        if(current.size() == 2 * n) {
            result.push_back(current);
            return;
        }

        if(openCount < n){
            generateParenthesisHelper(openCount + 1, closeCount, n, current + "(", result);
        }
        if(closeCount < openCount) {
            generateParenthesisHelper(openCount, closeCount + 1, n, current + ")", result);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesisHelper(0, 0, n, "", result);
        return result;
    }
};
int main(){
    Solution solution;
    //Test: n = 4
    vector<string> result1 = solution.generateParenthesis(4);
    for(string &a : result1){
        cout << a << endl;
    }
    return 0;
}
