/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        if (s.empty()) {
            return 0;
        }
        int idx = 0;
        while (s[idx] == ' ') {
            idx++;
        }
        if (idx != 0) {
            s = s.substr(idx, s.length() - idx);
        }
        bool positive = true;
        int64_t res(0);
        if (s[0] == '-') {
            positive = false;
        } else if (s[0] >= '0' && s[0] <= '9') {
            res = s[0] - '0';
        } else if (s[0] != '+') {
            return 0;
        }
        for (int i = 1; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                res = (10 * res) + s[i] - '0';
                if (res > INT32_MAX) {
                    res = INT32_MAX;
                    break;
                }
            } else {
                break;
            }
        }
        if (!positive) {
            if (res = INT32_MAX)
            res = -res;
        }
        return res;
    }
};
// @lc code=end

