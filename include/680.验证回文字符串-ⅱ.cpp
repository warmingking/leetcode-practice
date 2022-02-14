/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */

// @lc code=start

#include <string>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                return isPalindrme(s, i+1, j) || isPalindrme(s, i, j -1);
            }
        }
        return true;
    }

    bool isPalindrme(string s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
// @lc code=end

int main() {
    Solution s;
    bool ans = s.validPalindrome("deeee");
    return 0;
}
