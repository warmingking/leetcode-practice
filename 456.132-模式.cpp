/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132 模式
 */

// @lc code=start
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int min = nums[0];
        map<int, int> pattern13;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= min) {
                min = nums[i];
            } else {
                for (auto& p : pattern13) {
                    if (p.first >= nums[i]) {
                        break;
                    }
                    if (p.second > nums[i]) {
                        return true;
                    }
                }
                pattern13[min] = nums[i];
            }
        }
        return false;
    }
};
// @lc code=end

