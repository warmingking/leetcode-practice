/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length()+1, false);
        dp[0] = true;
        for (int i = 0; i <= s.length(); ++i) {
            for (auto& word : wordDict) {
                if (i < word.length()) {
                    continue;
                }
                if (s.substr(i-word.length(), word.length()) == word) {
                    dp[i] = dp[i] || dp[i-word.length()];
                }
                // cout << i << ": " << word << " " << dp[i] << endl;
            }
        }
        return dp[s.length()];
    }
};
// @lc code=end

