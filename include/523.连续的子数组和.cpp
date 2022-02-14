/*
 * @lc app=leetcode.cn id=523 lang=cpp
 *
 * [523] 连续的子数组和
 */

// @lc code=start
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) {
            return false;
        }
        vector<int> sums(nums.size(), nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            sums[i] = sums[i-1] + nums[i];
        }

        unordered_map<int, int> mods;
        for (int i = 0; i < sums.size(); ++i) {
            int m = sums[i] % k;
            if (m == 0 && i != 0) {
                return true;
            }
            auto it = mods.find(m);
            if (it != mods.end()) {
                int s = sums[i] - sums[it->second];
                if (i - it->second >= 2 && s % k == 0) {
                    return true;
                }
            } else {
                mods[m] = i;
            }
        }

        return false;
    }
};
// @lc code=end

