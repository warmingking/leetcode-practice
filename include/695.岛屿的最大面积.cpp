/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start

#include <cmath>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for (auto& v : grid) {
            v.insert(v.begin(), 0);
            v.emplace_back(0);
        }
        grid.insert(grid.begin(), vector<int>(grid[0].size(), 0));
        grid.emplace_back(vector<int>(grid[0].size(), 0));

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        int ans = 0;
        using Node = pair<int, int>;
        stack<Node> st;
        for (int i = 1; i < grid.size() - 1; ++i) {
            for (int j = 1; j < grid[0].size() - 1; ++j) {
                int area = 0;
                if (grid[i][j] == 1) {
                    area++;
                    st.emplace(i,j);
                    grid[i][j] = false;
                    while (!st.empty()) {
                        Node n = st.top();
                        st.pop();
                        for (auto& d : directions) {
                            if (grid[n.first+d.first][n.second+d.second] == 1) {
                                area++;
                                st.emplace(n.first+d.first, n.second+d.second);
                                grid[n.first+d.first][n.second+d.second] = 0;
                            }
                        }
                    }
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }

    // int dfs(vector<vector<int>>& grid, int cur_i, int cur_j) {
    //     if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != 1) {
    //         return 0;
    //     }
    //     grid[cur_i][cur_j] = 0;
    //     int di[4] = {0, 0, 1, -1};
    //     int dj[4] = {1, -1, 0, 0};
    //     int ans = 1;
    //     for (int index = 0; index != 4; ++index) {
    //         int next_i = cur_i + di[index], next_j = cur_j + dj[index];
    //         ans += dfs(grid, next_i, next_j);
    //     }
    //     return ans;
    // }

    // int maxAreaOfIsland(vector<vector<int>>& grid) {
    //     int ans = 0;
    //     for (int i = 0; i != grid.size(); ++i) {
    //         for (int j = 0; j != grid[0].size(); ++j) {
    //             ans = max(ans, dfs(grid, i, j));
    //         }
    //     }
    //     return ans;
    // }
};
// @lc code=end

int main() {
    Solution s;
    vector<vector<int>> input{
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    auto ans = s.maxAreaOfIsland(input);
    return 0;
}