/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
        long i = 0, j = (int) sqrt(c);
        while (i <= j) {
            long sum = i*i + j*j;
            if (sum == c) {
                return true;
            }
            else if (sum > c) {
                j--;
            }
            else {
                i++;
            }
        }
        return false;
    }
};
// @lc code=end

