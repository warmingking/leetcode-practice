/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int used = 0;
        int ans = 0;
        for (auto i : g) {
            bool found = false;
            while (used < s.size()) {
                if (s[used++] >= i) {
                    ans += 1;
                    found = true;
                    break;
                }
            }
            if (!found) {
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

