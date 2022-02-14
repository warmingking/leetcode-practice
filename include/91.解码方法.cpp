/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }

        vector<int> dp(s.length()+1, 1);
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == '0' && s[i-1] != '1' && s[i-1] != '2') {
                return 0;
            }
            if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) {
                if (s[i] == '0') {
                    dp[i+1] = dp[i-1];
                } else {
                    dp[i+1] = dp[i] + dp[i-1];
                }
            } else {
                dp[i+1] = dp[i];
            }
        }
        return dp[s.length()];
    }
};
// @lc code=end

