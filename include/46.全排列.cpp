/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
    vector<bool> marked;
    void dfs(const vector<int>& nums, vector<int>& prefix, vector<vector<int>>& ans) {
        if (prefix.size() == nums.size()) {
            ans.emplace_back(prefix);
            return;
        }

        for (int i = 0; i != marked.size(); ++i) {
            if (!marked[i]) {
                prefix.emplace_back(nums[i]);
                marked[i] = true;
                dfs(nums, prefix, ans);
                prefix.pop_back();
                marked[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        marked = vector<bool>(nums.size(), false);
        vector<vector<int>> ans;
        vector<int> prefix;
        dfs(nums, prefix, ans);
        return ans;
    }
};
// @lc code=end

