/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        // long left = 0;
        // long right = x;
        // while (left < right) {
        //     long mid = (left + right) / 2;
        //     long tmp = mid * mid;
        //     if (tmp == x) {
        //         return mid;
        //     } else if (tmp > x) {
        //         right = mid - 1;
        //     } else {
        //         left = mid + 1;
        //     }
        // }

        // return left * left <= x ? left : left-1;
        return sqrt(x);
    }
};
// @lc code=end

