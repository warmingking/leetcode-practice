/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void dfs(TreeNode* node, string& path, vector<string>& ans) {
        string tmp = path.empty() ? "" : "->";
        tmp += to_string(node->val);
        path += tmp;
        if (node->left == nullptr && node->right == nullptr) {
            ans.emplace_back(path);
        } else {
            if (node->left != nullptr) {
                dfs(node->left, path, ans);
            }
            if (node->right != nullptr) {
                dfs(node->right, path, ans);
            }
        }

        for (int i = 0; i < tmp.length(); ++i) {
            path.pop_back();
        }
    }
public:
    // vector<string> binaryTreePaths(TreeNode* root) {
    //     if (root == nullptr) {
    //         return {};
    //     }
    //     vector<string> ans;
    //     string path = "";
    //     dfs(root, path, ans);
    //     return ans;
    // }

    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        stack<pair<TreeNode*, string>> st;
        st.push({root, ""});
        vector<string> ans;
        while (!st.empty()) {
            auto node = st.top();
            st.pop();
            string tmp = node.second.empty() ? "" : "->";
            tmp += to_string(node.first->val);
            node.second += tmp;
            if (node.first->left == nullptr && node.first->right == nullptr) {
                ans.emplace_back(node.second);
            }
            if (node.first->right != nullptr) {
                st.push({node.first->right, node.second});
            }
            if (node.first->left != nullptr) {
                st.push({node.first->left, node.second});
            }
        }
        return ans;
    }
};
// @lc code=end

