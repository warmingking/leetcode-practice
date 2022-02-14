/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        vector<int> dp(amount+1, 0);
        for (auto& c : coins) {
            for (int i = c; i <= amount; ++i) {
                if (i == c) {
                    dp[i] = 1;
                } else if (dp[i-c] != 0) {
                    if (dp[i] == 0) {
                        dp[i] = dp[i-c] + 1;
                    } else {
                        dp[i] = min(dp[i-c] + 1, dp[i]);
                    }
                }
            }
        }
        return dp[amount] == 0 ? -1 : dp[amount];
    }
};
// @lc code=end

