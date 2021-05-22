/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:

    struct Status {
        int lsum; // 包含左节点时的最大值
        int rsum; // 包含右节点时的最大值
        int ssum; // 最大子序和
        int asum; // 所有元素的和
    };

    Status pushUp(Status& s1, Status& s2) {
        Status status;
        status.lsum = max(s1.lsum, s1.asum + s2.lsum);
        status.rsum = max(s2.rsum, s2.asum + s1.rsum);
        status.ssum = max(s1.ssum, s2.ssum);
        status.ssum = max(status.ssum, s1.rsum + s2.lsum);
        status.asum = s1.asum + s2.asum;
        return status;
    }

    Status get(vector<int>& nums, int left, int right) {
        if (left == right) {
            return Status{nums[left], nums[left], nums[left], nums[left]};
        }
        int mid = (right - left) / 2 + left;
        Status l_status = get(nums, left, mid);
        Status r_status = get(nums, mid+1, right);
        return pushUp(l_status, r_status);
    }

    int maxSubArray(vector<int>& nums) {
        // int dp = nums[0];
        // int ans = dp;
        // for (int i = 1; i < nums.size(); ++i) {
        //     dp = dp >= 0 ? (dp + nums[i]) : nums[i];
        //     ans = max(ans, dp);
        // }
        // return ans;

        return get(nums, 0, nums.size()-1).ssum;
    }
};
// @lc code=end

