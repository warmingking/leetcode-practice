/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start

#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
    string target;
    vector<pair<int, int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<bool>> marked;

    bool backtrack(vector<vector<char>>& board, int i, int j, string& prefix) {
        if (prefix.length() == target.length()
            && prefix.back() == target.back()) {
            return true;
        } else if (prefix.back() != target[prefix.length()-1]) {
            return false;
        }

        marked[i][j] = true;
        for (auto& dir : directions) {
            int x = i + dir.first;
            int y = j + dir.second;
            if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()
                || marked[x][y]) {
                continue;
            }
            prefix += board[x][y];
            if (backtrack(board, x, y, prefix)) {
                return true;
            }
            prefix.pop_back();
        }
        marked[i][j] = false;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        target = word;
        marked = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                string prefix = "";
                prefix += board[i][j];
                if (backtrack(board, i, j, prefix)) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<vector<char>> input = {{'a'}};
    string target = "b";
    auto ans = s.exist(input, target);
    return 0;
}