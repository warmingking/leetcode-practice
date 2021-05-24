/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
    /**
     * @brief 回溯
     * 考虑带上第 i 位时候的所有情况
     * 从 candidates 中移除 第 0 ~ i 位
     */
    void backtracking(vector<vector<int>>& ans, vector<int>& prefix, const vector<int>& candidates, int idx, int target) {
        if (target <= 0) {
            if (target == 0) {
                ans.emplace_back(prefix);
            }
            return;
        }

        for (auto i = idx; i < candidates.size(); ++i) {
            prefix.emplace_back(candidates[i]);
            backtracking(ans, prefix, candidates, i, target - candidates[i]);
            prefix.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> prefix;
        backtracking(ans, prefix, candidates, 0, target);
        return ans;
    }
};
// @lc code=end

