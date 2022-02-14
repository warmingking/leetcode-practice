/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int lowest = prices[0];
        int ans = 0;
        for (int i = 1; i < prices.size(); ++i) {
            ans = max(ans, prices[i] - lowest);
            lowest = min(lowest, prices[i]);
        }
        return ans;
    }
};
// @lc code=end

