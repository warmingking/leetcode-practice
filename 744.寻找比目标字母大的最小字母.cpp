/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (letters.back() <= target) {
            return letters[0];
        }
        int l = 0, r = letters.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (letters[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return letters[l];
    }
};
// @lc code=end

