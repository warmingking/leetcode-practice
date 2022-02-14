/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start

#include <stdlib.h>
using ll = long long;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0)
        {
            return 0;
        }
        if (dividend == std::numeric_limits<int>::min() && divisor == -1)
        {
            return std::numeric_limits<int>::max();
        }
        bool negative = (dividend ^ divisor) < 0;
        ll abs_dividend = abs(dividend);
        ll abs_divisor = abs(divisor);
        ll res = 0;
        ll mod = abs_divisor;
        while (abs_dividend - mod >= 0)
        {
            int i = 1;
            while ((mod << 1) <= abs_dividend)
            {
                mod <<= 1;
                i <<= 1;
            }
            res += i;
            abs_dividend -= mod;
            mod = abs_divisor;
        }
        return negative ? -res : res;
    }
};
// @lc code=end

