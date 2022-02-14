/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        s += target;
        if ((s & 1 == 1) || s - target < target) {
            return 0;
        }
        int W = s / 2;
        vector<int> dp(W+1, 0);
        dp[0] = 1;
        for (auto n : nums) {
            for (auto i = W; i >= n; --i) {
                dp[i] = dp[i] + dp[i-n];
            }
        }
        return dp[W];
    }
};
// @lc code=end

