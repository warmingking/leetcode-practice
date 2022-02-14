/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
    map<int, int> numCounts;
    map<int, int> marks;

    void dfs(const vector<int>& nums, vector<int>& prefix, vector<vector<int>>& ans) {
        if (prefix.size() == nums.size()) {
            ans.emplace_back(prefix);
            return;
        }

        for (auto& mark : marks) {
            if (mark.second < numCounts[mark.first]) {
                mark.second++;
                prefix.emplace_back(mark.first);
                dfs(nums, prefix, ans);
                prefix.pop_back();
                mark.second--;
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for (auto& i : nums) {
            numCounts[i]++;
            marks[i] = 0;
        }
        vector<vector<int>> ans;
        vector<int> prefix;
        dfs(nums, prefix, ans);
        return ans;
    }
};
// @lc code=end

