#include "0.common.hpp"

class Solution {
public:
    void run() {
        // test_case_1();
        TreeNode n5(5);
        TreeNode n4(4);
        TreeNode n3(3);
        TreeNode n2(2, &n4, &n5);
        TreeNode n1(1, &n2, &n3);

        TreeNode* node = upsideDownBinaryTree(&n1);

        queue<TreeNode*> q;
        q.push(node);
        while (true) {
            bool end = true;
            int s = q.size();
            while (s--) {
                TreeNode* cur = q.front();
                if (cur != nullptr) {
                    cout << cur->val << " ";
                    q.push(cur->left);
                    if (cur->left != nullptr) {
                        end = false;
                    }
                    q.push(cur->right);
                    if (cur->right != nullptr) {
                        end = false;
                    }
                } else {
                    cout << "nullptr ";
                    q.push(nullptr);
                    q.push(nullptr);
                }
                q.pop();
            }
            if (end) {
                cout << endl;
                break;
            }
        }
    }

    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode *right = nullptr, *father = nullptr;
        while (root != nullptr) {
            TreeNode* left = root->left;
            root->left = right;
            right = root->right;
            root->right = father;
            father = root;
            root = left;
        }

        return father;
    }
};
