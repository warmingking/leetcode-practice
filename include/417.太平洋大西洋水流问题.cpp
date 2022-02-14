/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start

#include <vector>
#include <unordered_set>
#include <map>
using namespace std;

class Solution {
    size_t m, n;
    vector<vector<bool>> pacifics;
    vector<vector<bool>> atlantics;

    vector<pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& marked) {
        marked[i][j] = true;
        for (auto& dir : directions) {
            int x = i + dir.first;
            int y = j + dir.second;
            if (x < m && y < n
                && x >= 0 && y >= 0
                && !marked[x][y]
                && heights[x][y] >= heights[i][j]) {
                dfs(heights, x, y, marked);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        pacifics = vector<vector<bool>> (m, vector<bool>(n, false));
        atlantics = pacifics;
        for (int i = 0; i < m; i++) {
            dfs(heights, i, 0, pacifics);
            dfs(heights, i, n -1, atlantics);
        }
        for (int i = 0; i < n; i++) {
            dfs(heights, 0, i, pacifics);
            dfs(heights, m - 1, i, atlantics);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacifics[i][j] && atlantics[i][j]) {
                    ans.emplace_back<vector<int>>({i, j});
                }
            }
        }
        return ans;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<vector<int>> input = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    auto ans = s.pacificAtlantic(input);
    return 0;
}