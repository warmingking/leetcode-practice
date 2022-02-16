#include "0.common.hpp"

class Solution {
public:
    void run() {
        TreeNode* n6 = new TreeNode(5);
        TreeNode* n5 = new TreeNode(5);
        TreeNode* n4 = new TreeNode(5);
        TreeNode* n3 = new TreeNode(1, nullptr, n6);
        TreeNode* n2 = new TreeNode(1, n4, n5);
        TreeNode* n1 = new TreeNode(1, n2, n3);

        int cnt = countUnivalSubtrees(n1);
        cout << "cnt: " << cnt << endl;
    }

    int countUnivalSubtrees(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        vector<map<TreeNode*, bool>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int s = q.size();
            map<TreeNode*, bool> m;
            while(s--) {
                TreeNode* cur = q.front();
                q.pop();
                m[cur] = true;
                if (cur->left != nullptr) {
                    q.push(cur->left);
                }
                if (cur->right != nullptr) {
                    q.push(cur->right);
                }
            }
            ans.emplace_back(move(m));
        }

        int level = ans.size();
        int cnt = ans[level-1].size();
        for (int i = level - 2; i >= 0; i--) {
            for (auto it = ans[i].begin(); it != ans[i].end(); it++) {
                bool same = true;
                if (it->first->left != nullptr) {
                    same &= ans[i+1][it->first->left];
                    same &= it->first->left->val == it->first->val;
                }
                if (same && it->first->right != nullptr) {
                    same &= ans[i+1][it->first->right];
                    same &= it->first->right->val == it->first->val;
                }
                if (same) {
                    cnt++;
                }
                it->second = same;
                cout << "it->first->val: " << it->first->val << ", same: " << same << endl;
            }
        }

        return cnt;
    }
};
