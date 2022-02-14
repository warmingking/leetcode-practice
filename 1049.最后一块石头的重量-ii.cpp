/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int s = accumulate(stones.begin(), stones.end(), 0);
        vector<int> dp(s/2 + 1, 0);
        for (int stone : stones) {
            for (int i = s/2; i >= stone; --i) {
                dp[i] = max(dp[i], dp[i-stone] + stone);
            }
        }
        return s - 2 * dp[s/2];
    }
};
// @lc code=end

