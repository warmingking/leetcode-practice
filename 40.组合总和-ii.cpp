/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    void dfs(vector<vector<int>>& ans,
             vector<int>& prefix,
             const vector<int>& candidates,
             int idx,
             int target) {
        if (target <= 0) {
            if (target == 0) {
                ans.emplace_back(prefix);
            }
            return;
        }

        for (int i = idx; i < candidates.size(); ++i) {
            prefix.emplace_back(candidates[i]);
            dfs(ans, prefix, candidates, i + 1, target - candidates[i]);
            prefix.pop_back();
            while (i < candidates.size() - 1 && candidates[i + 1] == candidates[i]) {
                i++;
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> prefix;
        dfs(ans, prefix, candidates, 0, target);
        return ans;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> input{2};
    auto ans = s.combinationSum2(input, 1);
    return 0;
}
