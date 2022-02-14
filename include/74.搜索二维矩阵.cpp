/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) {
            return false;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return false;
        }
        if (matrix[0][0] > target) {
            return false;
        }
        int possible_row;
        for (int left = 0, right = m - 1; left <= right;) {
            if (matrix[left][0] == target) {
                return true;
            }
            if (matrix[left][0] > target) {
                possible_row = left - 1;
                break;
            }
            if (left == right) {
                possible_row = left;
                break;
            }
            int mid = (left + right) / 2;
            if (matrix[mid][0] == target) {
                return true;
            }
            if (matrix[mid][0] < target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        if (possible_row < 0) {
            return false;
        }
        int idx;
        for (int left = 0, right = n - 1; left <= right; ) {
            if (left == right) {
                return matrix[possible_row][left] == target;
            }
            int mid = (left + right) / 2;
            if (matrix[possible_row][mid] == target) {
                return true;
            }
            if (matrix[possible_row][mid] < target) {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return false;
    }
};
// @lc code=end

