/*
 * @lc app=leetcode.cn id=650 lang=cpp
 *
 * [650] 只有两个键的键盘
 */

// @lc code=start
class Solution {
public:
    int minSteps(int n) {
        int ans = 0, d = 2;
        while (n > 1) {
            while (n % d == 0) {
                ans += d;
                n /= d;
            }
            d++;
        }
        return ans;
    }
};
// @lc code=end

