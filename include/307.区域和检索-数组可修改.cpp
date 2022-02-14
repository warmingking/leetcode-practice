/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */

// @lc code=start
class NumArray {
    struct SegmentTreeNode {
        SegmentTreeNode* left;
        SegmentTreeNode* right;
        int start;
        int end;
        int val;

        SegmentTreeNode() : left(nullptr), right(nullptr) {}
    };

    SegmentTreeNode* buildTree(vector<int>& nums, int start, int end) {
        int m = start + (end - start) / 2;
        SegmentTreeNode* node = new SegmentTreeNode;
        node->start = start;
        node->end = end;
        if (start == end) {
            node->val = nums[start];
        } else {
            node->left = buildTree(nums, start, m);
            node->right = buildTree(nums, m+1, end);
            node->val = node->left->val + node->right->val;
        }
        return node;
    }

    void updateTree(SegmentTreeNode* node, int idx, int val) {
        if (node->start == idx && node->end == idx) {
            node->val = val;
            return;
        }
        int m = node->start + (node->end - node->start) / 2;
        if (idx <= m) {
            updateTree(node->left, idx, val);
        } else {
            updateTree(node->right, idx, val);
        }
        node->val = node->left->val + node->right->val;
    }

    int sumRangeTree(SegmentTreeNode* node, int start, int end) {
        if (node->start == start && node->end == end) {
            return node->val;
        }
        int m = node->start + (node->end - node->start) / 2;
        if (end <= m) {
            return sumRangeTree(node->left, start, end);
        } else if (start > m) {
            return sumRangeTree(node->right, start, end);
        } else {
            return sumRangeTree(node->left, start, m) + sumRangeTree(node->right, m+1, end);
        }
    }

    SegmentTreeNode* root;

public:
    NumArray(vector<int>& nums) {
        root = buildTree(nums, 0, nums.size()-1);
    }

    void update(int index, int val) {
        updateTree(root, index, val);
    }

    int sumRange(int left, int right) {
        return sumRangeTree(root, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

