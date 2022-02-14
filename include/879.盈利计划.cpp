/*
 * @lc app=leetcode.cn id=879 lang=cpp
 *
 * [879] 盈利计划
 */

// @lc code=start
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<int>> dp(n+1, vector<int>(minProfit+1, 0));
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }
        int MOD = (int)1e9 + 7;
        for (int i = 0; i < group.size(); ++i) {
            for (int j = n; j >= group[i]; --j) {
                for (int k = minProfit; k >= 0; --k) {
                    dp[j][k] = (dp[j][k] + dp[j-group[i]][max(0, k-profit[i])]) % MOD;
                }
            }
        }
        return dp[n][minProfit];
    }
};
// @lc code=end

