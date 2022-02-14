/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int ans = 0;
        // bool toBuy = true;
        // int cur = prices[0];
        // int buyPrice = 0;
        // for (int i = 1; i < prices.size(); ++i) {
        //     if (toBuy) {
        //         if (prices[i] > cur) {
        //             buyPrice = cur;
        //             toBuy = false;
        //         } 
        //     }
        //     if (!toBuy) {
        //         if (prices[i] < cur) {
        //             ans += cur - buyPrice;
        //             toBuy = true;
        //         }
        //     }
        //     cur = prices[i];
        // }
        // if (!toBuy) {
        //     ans += prices.back() - buyPrice;
        // }

        for (auto i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i-1]) {
                ans += prices[i] - prices[i-1];
            }
        }
        return ans;
    }
};
// @lc code=end

