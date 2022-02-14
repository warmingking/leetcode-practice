/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 */

// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        auto len = nums.size();
        if (len < 3) {
            return 0;
        }
        int ans = 0;
        int curLen = 2;
        for (auto i = 2; i < len; ++i) {
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                curLen++;
                ans += curLen - 3 + 1;
            } else {
                curLen = 2;
            }
        }
        return ans;
    }
};
// @lc code=end

