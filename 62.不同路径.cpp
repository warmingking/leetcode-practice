/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (auto i = 1; i < m; ++i) {
            for (auto j = 1; j < n; ++j) {
                dp[j] = dp[j] + dp[j-1];
            }
        }
        return dp[n-1];
    }
};
// @lc code=end

