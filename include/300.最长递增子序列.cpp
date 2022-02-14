/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        vector<int> tails;
        tails.emplace_back(nums[0]);
        int ans = dp[0];
        for (auto i = 1; i < nums.size(); ++i) {
            auto it = lower_bound(tails.begin(), tails.end(), nums[i]);
            if (it == tails.end()) {
                if (nums[i] > tails.back()) {
                    tails.emplace_back(nums[i]);
                }
                dp[i] = tails.size();
            } else {
                dp[i] = it - tails.begin() + 1;
                *it = nums[i];
            }
            // cout << i << " " << dp[i] << endl;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> input{4,10,4,3,8,9};
    auto ans = s.lengthOfLIS(input);
    return 0;
}