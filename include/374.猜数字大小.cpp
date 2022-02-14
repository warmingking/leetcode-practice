/*
 * @lc app=leetcode.cn id=374 lang=cpp
 *
 * [374] 猜数字大小
 */

// @lc code=start
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1;
        while (l < n) {
            int mid = (n - l) / 2 + l;
            int g = guess(mid);
            if (g == 0) {
                return mid;
            }
            if (g < 0) {
                n = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
// @lc code=end

