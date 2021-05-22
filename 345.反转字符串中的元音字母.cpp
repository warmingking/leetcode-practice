/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start

#include <string>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            bool left = isVowel(s[i]);
            bool right = isVowel(s[j]);
            if (left && right) {
                char c = s[i];
                s[i] = s[j];
                s[j] = c;
                i++;
                j--;
            }
            else {
                if (!left) {
                    i++;
                }
                if (!right) {
                    j--;
                }
            }
        }
        return s;
    }

    bool isVowel(char c) {
        switch (c)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return true;
        default:
            return false;
        }
    }

};
// @lc code=end

int main() {
    Solution s;
    string ans = s.reverseVowels("hello");
    return 0;
}