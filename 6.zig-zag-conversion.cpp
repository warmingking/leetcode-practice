/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) { // 如果 numRows == 1, 原样返回
            return s;
        }
        // 每一行的 2 个数,
        // 要么相差 2 * (numRows - i - 1)
        // 要么相差 2 * i
        // 第一行和最好一行需要特判, 每 2 个数相差 2 * (numRows - 1)
        string res("");
        for (int i = 0; i < numRows; i++) {
            int d_total = 2 * (numRows - 1);
            int d_begin = 2 * (numRows - i - 1);
            for (int j = i; j < s.length();) {
                res.push_back(s[j]);
                if (d_begin == 0) {
                    d_begin = d_total;
                }
                j = j + d_begin;
                d_begin = d_total - d_begin;
            }
        }
        return res;
    }
};
// @lc code=end

