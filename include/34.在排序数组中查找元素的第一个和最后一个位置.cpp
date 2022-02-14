/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }

        vector<int> ans(2);
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = (r - l) / 2 + l;
            if (nums[m] >= target) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        if (nums[l] != target) {
            return {-1, -1};
        }
        ans[0] = l;

        r = nums.size();
        target++;
        while (l < r) {
            int m = (r - l) / 2 + l;
            if (nums[m] >= target) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        ans[1] = l - 1;

        return ans;

    }
};
// @lc code=end

