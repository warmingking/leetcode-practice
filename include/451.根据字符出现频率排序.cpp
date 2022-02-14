/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start

#include <string>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> freq;
        for (auto c : s) {
            ++freq[c];
        }
        priority_queue<pair<int, char>> pq;
        for (auto& it : freq) {
            pq.push(pair<int, char>(it.second, it.first));
        }
        string ans;
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            while (p.first--) {
                ans += p.second;
            }
        }
        return ans;
    }
};
// @lc code=end

