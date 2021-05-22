/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
            return a[1] < b[1];
        });
        int cnt = 0;
        int end = intervals[0][1];
        for (int j = 1; j < intervals.size(); j++) {
            if (end > intervals[j][0]) {
                cnt++;
            } else {
                end = intervals[j][1];
            }
        }
        return cnt;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<vector<int>> input;
    input.emplace_back<vector<int>>({0,2});
    input.emplace_back<vector<int>>({1,3});
    input.emplace_back<vector<int>>({2,4});
    input.emplace_back<vector<int>>({3,5});
    input.emplace_back<vector<int>>({4,6});
    int ans = s.eraseOverlapIntervals(input);
    return 0;
}