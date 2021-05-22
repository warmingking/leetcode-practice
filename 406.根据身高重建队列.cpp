/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b){
            if (a[0] < b[0]) {
                return true;
            } else if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return false;
        });

        vector<vector<int>> ans(people.size(), vector<int>{-1, -1});
        for (auto v : people) {
            int k = v[1];
            for (int i = 0; i < ans.size(); i++) {
                if (ans[i][0] == -1) {
                    if (k == 0) {
                        ans[i] = v;
                        break;
                    } else {
                        k--;
                    }
                }
            }
        }
        people = ans;
        return ans;
    }
};
// @lc code=end

