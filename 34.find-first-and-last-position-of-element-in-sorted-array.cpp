/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return vector<int>{-1, -1};
        }
        int len = nums.size();
        if (target < nums[0] || target > nums[len - 1]) {
            return vector<int>{-1, -1};
        }
        int left = 0, right = len - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target) {
                right = mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                int x = searchLastSmaller(nums, left, mid, target);
                int y = searchFirstLarger(nums, mid, right, target);
                return vector<int>{x+1, y-1};
            }
        }
        if (nums[left] == target) {
            return vector<int>{left, right};
        }
        return vector<int>{-1, -1};
    }

    int searchFirstLarger(vector<int>& nums, int left, int right, int target) {
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return nums[left] > target ? left : (right + 1);
    }

    int searchLastSmaller(vector<int>& nums, int left, int right, int target) {
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return nums[right] < target ? right : (left - 1);
    }
};
// @lc code=end

