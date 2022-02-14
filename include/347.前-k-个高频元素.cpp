/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> bucket;
        for (auto n : nums) {
            ++bucket[n];
        }

        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for (auto& item : bucket) {
            pq.push(pair<int, int>(item.second, item.first));
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> ans;
        while (!pq.empty()) {
            ans.emplace_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
// @lc code=end

