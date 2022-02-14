/*
 * @lc app=leetcode.cn id=1091 lang=cpp
 *
 * [1091] 二进制矩阵中的最短路径
 */

// @lc code=start

#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0) {
            return -1;
        }
        for (auto& v : grid) {
            v.insert(v.begin(), 1);
            v.emplace_back(1);
        }
        grid.insert(grid.begin(), vector<int>(n+2, 1));
        grid.emplace_back(vector<int>(n+2, 1));

        int ans = 0;

        using Node = pair<int, int>;
        Node end{n,n};
        queue<Node> curNodes;
        Node lastNode{1, 1};
        curNodes.push(lastNode);
        grid[1][1] = 1;
        while (!curNodes.empty()) {
            ans++;
            auto size = curNodes.size();
            while (size--) {
                Node node = curNodes.front();
                if (node == end) {
                    return ans;
                }
                curNodes.pop();
                if (grid[node.first + 1][node.second] == 0) {
                    Node n{node.first+1, node.second};
                    if (n == end) {
                        return ++ans;
                    }
                    curNodes.push(n);
                    grid[n.first][n.second] = 1;
                }
                if (grid[node.first][node.second+1] == 0) {
                    Node n{node.first, node.second+1};
                    if (n == end) {
                        return ++ans;
                    }
                    curNodes.push(n);
                    grid[n.first][n.second] = 1;
                }
                if (grid[node.first + 1][node.second + 1] == 0) {
                    Node n{node.first+1, node.second+1};
                    if (n == end) {
                        return ++ans;
                    }
                    curNodes.push(n);
                    grid[n.first][n.second] = 1;
                }
                if (grid[node.first - 1][node.second - 1] == 0) {
                    Node n{node.first-1, node.second-1};
                    if (n == end) {
                        return ++ans;
                    }
                    curNodes.push(n);
                    grid[n.first][n.second] = 1;
                }
                if (grid[node.first - 1][node.second + 1] == 0) {
                    Node n{node.first-1, node.second+1};
                    if (n == end) {
                        return ++ans;
                    }
                    curNodes.push(n);
                    grid[n.first][n.second] = 1;
                }
                if (grid[node.first + 1][node.second - 1] == 0) {
                    Node n{node.first+1, node.second-1};
                    if (n == end) {
                        return ++ans;
                    }
                    curNodes.push(n);
                    grid[n.first][n.second] = 1;
                }
                if (grid[node.first - 1][node.second] == 0) {
                    Node n{node.first-1, node.second};
                    if (n == end) {
                        return ++ans;
                    }
                    curNodes.push(n);
                    grid[n.first][n.second] = 1;
                }
                if (grid[node.first][node.second - 1] == 0) {
                    Node n{node.first, node.second-1};
                    if (n == end) {
                        return ++ans;
                    }
                    curNodes.push(n);
                    grid[n.first][n.second] = 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<vector<int>> input{{0,0,0},{1,1,0},{1,1,0}};
    auto ans = s.shortestPathBinaryMatrix(input);
    return 0;
}