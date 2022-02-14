/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) {
            return true;
        }
        for(int i = 0, j = 0; j < t.length(); ++j) {
            if (t[j] == s[i]) {
                i++;
                if (i >= s.length()) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

