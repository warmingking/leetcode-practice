/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start

#include <vector>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int s = sqrt(n);
        vector<int> squares;
        for (int i = 1; i <= s; ++i) {
            squares.emplace_back(i*i);
        }

        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < s && i >= squares[j]; ++j) {
                dp[i] = min(dp[i], dp[i-squares[j]]);
            }
            dp[i]++;
        }
        return dp[n];
    }
};
// @lc code=end

int main() {
    Solution s;
    auto ans = s.numSquares(12);
    return 0;
}