/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int l = 0, h = nums.size() - 1;
        while (l < h) {
            int m = l + (h - l) / 2;
            if (m & 1) {
                m--;   // 保证 l/h/m 都在偶数位，使得查找区间大小一直都是奇数
            }
            if (nums[m] == nums[m + 1]) {
                l = m + 2;
            } else {
                h = m;
            }
        }
        return nums[l];
    }
};
// @lc code=end

