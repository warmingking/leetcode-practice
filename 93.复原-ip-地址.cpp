/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
    /**
     * params
     * s: origin string
     * idx: cur index of string
     * prefix: temp address
     * k: segment number of temp address
     * ans(out): ip address
     */
    void doRestore(string& s, int idx, string& prefix, int k, vector<string>& ans) {
        if (k == 4 || idx == s.length()) {
            if (k == 4 && idx == s.length()) {
                ans.emplace_back(prefix);
            }
            return;
        }

        for (int i = 0; i < s.length() - idx && i <= 2; ++i) {
            if (i != 0 && s[idx] == '0') {
                break;
            }
            string subs = s.substr(idx, i+1);
            if (stoi(subs) < 256) {
                if (k != 0) {
                    prefix += '.';
                }
                prefix += subs;
                doRestore(s, idx + i + 1, prefix, k + 1, ans);
                for (int j = 0; j < i + 2 && !prefix.empty(); ++j) {
                    prefix.pop_back();
                }
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string prefix = "";
        doRestore(s, 0, prefix, 0, ans);
        return ans;
    }
};
// @lc code=end

