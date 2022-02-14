/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        auto len = temperatures.size();
        if (len == 0) {
            return {};
        }

        multiset<pair<int, int>> temps;
        temps.emplace(temperatures[len-1], len-1);

        vector<int> ans(len, 0);
        for (int i = len-2; i >= 0; --i) {
            int cnt = 1;
            for (auto& p : temps) {
                if (p.first > temperatures[i]) {
                    ans[i] = cnt;
                    break;
                }
                cnt++;
            }
            temps.emplace(temperatures[i], i);
        }
        return ans;
    }
};
// @lc code=end

