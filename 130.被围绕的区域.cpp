/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
    using Point = pair<int, int>;
    vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int m, n;

    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return;
        }
        if (board[i][j] != 'O') {
            return;
        }
        board[i][j] = 'T';
        for (auto& po : directions) {
            dfs(board, i + po.first, j + po.second);
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; ++i) {
            dfs(board, i, 0);
            dfs(board, i, n-1);
        }
        for (int i = 0; i < n; ++i) {
            dfs(board, 0, i);
            dfs(board, m-1, i);
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
// @lc code=end

