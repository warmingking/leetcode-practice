/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        int a = 1;
        int b = 1;
        for (int i = 2; i <= n; ++i) {
            b += a;
            a = b - a;
        }
        return b;
    }
};
// @lc code=end

