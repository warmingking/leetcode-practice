/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        /* 0: 持有一支股票, 累计最大收益
        *  1: 处于冷冻期, 累计最大收益
        *  2: 不持有股票, 也不在冷冻期, 累计最大收益
        *  这里的「处于冷冻期」指的是在第 i 天结束之后的状态
        *  也就是说
        *      如果第 i 天结束之后处于冷冻期，那么第 i+1 天无法买入股票
        */
        vector<vector<int>> dp(len, vector<int>(3, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;
        for (int i = 1; i < len; ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][2] - prices[i]);
            dp[i][1] = dp[i-1][0] + prices[i];
            dp[i][2] = max(dp[i-1][1], dp[i-1][2]);
        }
        return max(dp[len-1][1], dp[len-1][2]);
    }
};
// @lc code=end

