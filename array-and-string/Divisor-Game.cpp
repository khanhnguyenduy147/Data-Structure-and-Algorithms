#include <iostream>
#include <vector>

class Solution {
public:
    bool divisorGame(int n) {
        std::vector<bool> dp(n + 1, false);
        dp[1] = false; // Base case

        for (int i = 2; i <= n; ++i) {
            for (int x = 1; x < i; ++x) {
                if (i % x == 0 && !dp[i - x]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};

int main() {
    Solution solution;

    // Test cases
    std::cout << "Test Case 1: " << (solution.divisorGame(2) ? "true" : "false") << std::endl;
    std::cout << "Test Case 2: " << (solution.divisorGame(3) ? "true" : "false") << std::endl;

    return 0;
}
