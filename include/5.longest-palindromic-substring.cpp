/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s)
    {
        // 含义: s[i] ~ s[j] 是否为回文字符串
        // 只考虑上三角矩阵
        vector<vector<bool>> isPalindrome(s.length(), vector<bool>(s.length(), true));
        int left(0), max(0);
        for (int i = s.length() - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < s.length(); j++)
            {
                // 递推公式: isPalindrome[i][j] = isPalindrome[i+1][j-1] && s[i] == s[j]
                if (s[i] == s[j])
                {
                    if (j == i + 1)
                    {
                        isPalindrome[i][j] = true;
                    }
                    else
                    {
                        isPalindrome[i][j] = isPalindrome[i+1][j-1];
                    }
                }
                else
                {
                    isPalindrome[i][j] = false;
                }
                if (isPalindrome[i][j] && (j - i + 1 > max))
                {
                    left = i;
                    max = j - i + 1;
                }
            }
        }
        if (max == 0)
        {
            return s.empty() ? s : s.substr(0, 1);
        }
        return s.substr(left, max);
    }
};
// @lc code=end

