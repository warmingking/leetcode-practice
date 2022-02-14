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
        cout << "succ " << node->val << " succ" << endl;
    }

    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        function<TreeNode*(TreeNode*)> f = [f](TreeNode* node) {
            if (node == nullptr || node->left == nullptr) {
                return node;
            }
            TreeNode* l = node->left;
            TreeNode* r = node->right;
            TreeNode* ll = f(l);
            TreeNode* rr = f(r);
            ll->left = rr;
            ll->right = node;
            return ll;
        };

        return f(root);
    }
};
