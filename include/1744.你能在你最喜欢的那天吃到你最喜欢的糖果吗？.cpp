/*
 * @lc app=leetcode.cn id=1744 lang=cpp
 *
 * [1744] 你能在你最喜欢的那天吃到你最喜欢的糖果吗？
 */

// @lc code=start
class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        vector<long> sumCount(candiesCount.size(), candiesCount[0]);
        for (int i = 1; i < candiesCount.size(); ++i) {
            sumCount[i] = sumCount[i-1] + candiesCount[i];
        }

        vector<bool> ans;
        for (auto& query : queries) {
            ans.emplace_back(query[1] < sumCount[query[0]] && query[1]+1 > (sumCount[query[0]] - candiesCount[query[0]]) / query[2]);
        }
        return ans;
    }
};
// @lc code=end

