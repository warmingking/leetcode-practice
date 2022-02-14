/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1 == 1) {
            return false;
        }
        int W = sum / 2;
        vector<bool> dp(W+1, false); // 是否恰巧找到和为i的组合
        dp[0] = true;
        for (int num : nums) {
            for (int i = W; i >= num; --i) {
                dp[i] = dp[i] || dp[i-num];
            }
        }
        return dp[W];
    }
};
// @lc code=end

