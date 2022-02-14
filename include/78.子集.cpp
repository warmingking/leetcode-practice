/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> res(1<<len);
        for (int i = 0; i < (1<<len); ++i) {
            for (int j = i, idx = 0; j > 0; j >>= 1) {
                if (j & 1) {
                    res[i].push_back(nums[idx]);
                }
                idx++;
            }
        }
        return res;
    }
};
// @lc code=end

