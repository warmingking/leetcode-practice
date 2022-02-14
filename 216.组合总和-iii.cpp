/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
    void dfs(vector<vector<int>>& ans, vector<int>& prefix, int idx, int k, int target) {
        if (target > 9*(k-prefix.size()) || target < idx*(k-prefix.size())) {
            return;
        }
        if (target == 0 && prefix.size() == k) {
            ans.emplace_back(prefix);
            return;
        }

        for (int i = idx; i <= 9; ++i) {
            prefix.emplace_back(i);
            dfs(ans, prefix, i+1, k, target - i);
            prefix.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> prefix;
        dfs(ans, prefix, 1, k, n);
        return ans;
    }
};
// @lc code=end

