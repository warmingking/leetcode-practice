/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (auto& s : strs) {
            int zero = 0, one = 0;
            for (char c : s) {
                if (c == '0') {
                    zero++;
                } else {
                    one++;
                }
            }

            // cout << zero << " " << one << endl;
            for (int i = m; i >= zero; --i) {
                for (int j = n; j >= one; --j) {
                    dp[i][j] = max(dp[i-zero][j-one] + 1, dp[i][j]);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end
