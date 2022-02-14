/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int len = arr.size();
        int l = 1, r = len - 2;
        while (l < r) {
            int m = (r - l) / 2 + l;
            if (arr[m] > arr[m - 1] && arr[m] > arr[m + 1]) {
                return m;
            } else if (arr[m] < arr[m - 1]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};
// @lc code=end

