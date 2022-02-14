/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132 模式
 */

// @lc code=start
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> num_3s;
        int num_2 = INT_MIN;
        num_3s.push(nums.back());
        for (int i = nums.size()-2; i >= 0; --i) {
            if (nums[i] < num_2) {
                return true;
            }
            while (!num_3s.empty() && num_3s.top() < nums[i]) {
                num_2 = num_3s.top();
                num_3s.pop();
            }
            if (nums[i] > num_2) {
                num_3s.push(nums[i]);
            }
        }
        return false;
    }
};
// @lc code=end

