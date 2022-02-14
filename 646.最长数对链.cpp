/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链
 */

// @lc code=start
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        // for (auto& p : pairs) {
        //     cout << p[0] << " " << p[1] << endl;
        // }
        int ans = 1;
        int lastIdx = 0;
        for (int i = 1; i < pairs.size(); ++i) {
            if (pairs[i][0] > pairs[lastIdx][1]) {
                ans++;
                lastIdx = i;
            }
        }
        return ans;
    }
};
// @lc code=end

