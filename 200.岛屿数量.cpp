/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        for (auto& v : grid) {
            v.insert(v.begin(), '0');
            v.emplace_back('0');
        }
        grid.insert(grid.begin(), vector<char>(grid[0].size(), '0'));
        grid.emplace_back(vector<char>(grid[0].size(), '0'));

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        int ans = 0;
        using Node = pair<int, int>;
        stack<Node> st;
        for (int i = 1; i < grid.size() - 1; ++i) {
            for (int j = 1; j < grid[0].size() - 1; ++j) {
                if (grid[i][j] == '1') {
                    ans++;
                    st.emplace(i,j);
                    grid[i][j] = '0';
                    while (!st.empty()) {
                        Node n = st.top();
                        st.pop();
                        for (auto& d : directions) {
                            if (grid[n.first+d.first][n.second+d.second] == '1') {
                                st.emplace(n.first+d.first, n.second+d.second);
                                grid[n.first+d.first][n.second+d.second] = '0';
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

