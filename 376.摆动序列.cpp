/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        vector<int> vec;
        int lastDir = 0; // 0 表示未知, -1 表示上一次是减小, 1 表示上一次是增大
        vec.emplace_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            int x = nums[i] - vec.back();
            if (x == 0) {
                continue;
            }
            if (lastDir == 0) {
                if (x < 0) {
                    lastDir = -1;
                    vec.emplace_back(nums[i]);
                } else if (x > 0) {
                    lastDir = 1;
                    vec.emplace_back(nums[i]);
                }
            } else if (lastDir * x < 0) {
                lastDir *= -1;
                vec.emplace_back(nums[i]);
            } else {
                vec.pop_back();
                vec.emplace_back(nums[i]);
            }
        }
        return vec.size();
    }
};
// @lc code=end

