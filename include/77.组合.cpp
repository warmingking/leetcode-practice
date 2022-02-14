/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
    int k;
    int n;
    void backtracking(vector<vector<int>>& ans, vector<int>& prefix, int idx) {
        if (prefix.size() == k) {
            ans.emplace_back(prefix);
            return;
        }

        for (auto i = idx+1; i <= n; ++i) {
            prefix.emplace_back(i);
            backtracking(ans, prefix, i);
            prefix.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;

        vector<vector<int>> ans;
        vector<int> prefix;
        backtracking(ans, prefix, 0);
        return ans;
    }
};
// @lc code=end

