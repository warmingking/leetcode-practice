/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (auto& s : strs) {
            int zeros(0), ones(0);
            for (char c : s) {
                if (c == '0') {
                    zeros++;
                } else {
                    ones++;
                }
            }
            for (int i = m; i >= zeros; i--) {
                for (int j = n; j >= ones; j--) {
                    dp[i][j] = max(dp[i-zeros][j-ones] + 1, dp[i][j]);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<string> input{"10","0001","111001","1","0"};
    auto ans = s.findMaxForm(input, 5, 3);
    return 0;
}