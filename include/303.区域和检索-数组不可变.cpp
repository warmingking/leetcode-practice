/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
    vector<int> ansArray;
public:
    NumArray(vector<int>& nums) {
        ansArray.emplace_back(0);
        int sum = 0;
        for (auto i : nums) {
            sum += i;
            ansArray.emplace_back(sum);
        }
    }

    int sumRange(int left, int right) {
        return ansArray[right+1] - ansArray[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

