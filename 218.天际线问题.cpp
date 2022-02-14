/*
 * @lc app=leetcode.cn id=218 lang=cpp
 *
 * [218] 天际线问题
 */

// @lc code=start

#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> heights;
        for (auto& building : buildings) {
            heights.emplace_back(vector<int>{building[0], -building[2]});
            heights.emplace_back(vector<int>{building[1], building[2]});
        }
        sort(heights.begin(), heights.end());
        int preHeight = 0;
        multiset<int> curHeights{0};
        vector<vector<int>> ans;
        for (auto& vec : heights) {
            if (vec[1] > 0) {
                curHeights.erase(curHeights.find(-vec[1]));
            } else {
                curHeights.insert(vec[1]);
            }
            if (*curHeights.begin() != -preHeight) {
                preHeight = 0 - *curHeights.begin();
                ans.emplace_back(vector<int>{vec[0], preHeight});
                // if (!ans.empty() && vec[0] == ans.back()[0]) {
                //     ans.pop_back();
                // }
                // if (ans.empty() || preHeight != ans.back()[1]) {
                //     ans.emplace_back(vector<int>{vec[0], preHeight});
                // }
            }
        }
        return ans;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<vector<int>> input{{0,2,3}, {2,5,3}};
    auto ans = s.getSkyline(input);
    return 0;
}