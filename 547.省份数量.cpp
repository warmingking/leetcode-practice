/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> connections(isConnected.size());
        vector<bool> marked(isConnected.size(), false);

        for (int i = 0; i < isConnected.size(); ++i) {
            for (int j = 0; j < isConnected.size(); ++j) {
                if (isConnected[i][j] == 1) {
                    connections[i].emplace_back(j);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < connections.size(); ++i) {
            if (marked[i]) {
                continue;
            }
            marked[i] = true;
            stack<int> st;
            st.push(i);
            while (!st.empty()) {
                int x = st.top();
                st.pop();
                for (int j : connections[x]) {
                    if (!marked[j]) {
                        st.push(j);
                        marked[j] = true;
                    }
                }
            }

            ans++;
        }
        return ans;
    }
};
// @lc code=end

