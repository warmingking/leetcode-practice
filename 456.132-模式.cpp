/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132 模式
 */

// @lc code=start
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        map<int, int> patten13;
        for (int i = 0; i < nums.size(); ++i) {
            if (patten13.count(nums[i]) == 0) {
                patten13[nums[i]] = INT_MIN;
            } else {
                patten13[nums[i]] = max(nums[i], patten13[nums[i]]);
            }
            for (auto p : patten13) {
                if (p.first >= nums[i]) {
                    break;
                }
                if (p.first < nums[i] && nums[i] < p.second) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

