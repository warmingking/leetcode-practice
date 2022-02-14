/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for (int c : coins) {
            for (int i = c; i <= amount; ++i) {
                dp[i] = dp[i] + dp[i - c];
            }
        }
        return dp[amount];
    }
};
// @lc code=end

