/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        if (temperatures.empty()) {
            return {};
        }
        vector<int> ans(temperatures.size(), 0);
        stack<pair<int,int>> temps;
        temps.emplace(temperatures[0], 0);
        for (int i = 1; i < temperatures.size(); ++i) {
            while (!temps.empty() && temps.top().first < temperatures[i]) {
                auto& p = temps.top();
                ans[p.second] = i - p.second;
                temps.pop();
            }
            temps.emplace(temperatures[i], i);
        }
        return ans;
    }
};
// @lc code=end

