/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int removed = 0;
        for (int i = 0; i < nums.size() - removed; ++i) {
            if (nums[i] == val) {
                for (int j = nums.size() - 1 - removed; j > i; --j) {
                    if (nums[j] != val) {
                        nums[i] = nums[j];
                        // nums[j] = val;
                        break;
                    }
                    else {
                        removed++;
                    }
                }
                removed++;
            }
        }
        return nums.size() - removed;
    }
};
// @lc code=end

