/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 1) {
            if (nums[0] == target) {
                return 0;
            }
        }
        int i = 0, j = len - 1;
        while (i < j) {
            int mid = (i + j) / 2;
            if (nums[i] == target) {
                return i;
            }
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[j] == target) {
                return j;
            }
            // 前半段递增
            if (nums[mid] > nums[i]) {
                if (target < nums[i]) {
                    i = mid + 1;
                }
                else if (target > nums[mid]) {
                    i = mid;
                }
                else {
                    j = mid;
                }
            }
            // 前半段有转折, 后半段肯定递增
            else {
                if (target > nums[i]) {
                    j = mid;
                }
                else if (target < nums[mid]) {
                    j = mid;
                }
                else {
                    i = mid + 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

