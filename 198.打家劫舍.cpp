/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int ans = 0;
        vector<int> dp(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0) {
                dp[i] = nums[i];
            } else if (i == 1) {
                dp[i] = max(nums[0], nums[1]);
            } else {
                dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// @lc code=end

