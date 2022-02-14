/*
 * @lc app=leetcode.cn id=1449 lang=cpp
 *
 * [1449] 数位成本和为目标值的最大数字
 */

// @lc code=start

#include <string>
#include <vector>
using namespace std;

class Solution {
    bool lessStringInt(const string& s1, const string& s2) {
        if (s1.length() < s2.length()) {
            return true;
        } else if (s1.length() > s2.length()) {
            return false;
        } else {
            return s1 < s2;
        }
    }

public:
    string largestNumber(vector<int>& cost, int target) {
        int m = cost.size();
        vector<string> dp(target + 1, "0");
        dp[0] = "";
        for (int i = m; i >= 1; --i) {
            for (int j = cost[i-1]; j <= target; ++j) {
                if (dp[j - cost[i-1]] != "0") {
                    string tmp = dp[j-cost[i-1]] + to_string(i);
                    if (lessStringInt(dp[j], tmp)) {
                        dp[j] = tmp;
                    }
                }
            }
        }
        return dp[target];
    }
};
// @lc code=end

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> cost = {13,12,9,12,15,11,10,11,15};
    auto ans = s.largestNumber(cost, 52);
    return 0;
}