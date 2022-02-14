/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 1;
        for (auto i = 3; i <= n; ++i) {
            dp[i] = max(dp[i], 2 * (i - 2));
            dp[i] = max(dp[i], 2 * dp[i-2]);
            dp[i] = max(dp[i], 3 * (i - 3));
            dp[i] = max(dp[i], 3 * dp[i-3]);
        }
        return dp[n];
    }
};
// @lc code=end

