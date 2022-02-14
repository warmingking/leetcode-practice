#include "iostream"
#include "vector"
#include "algorithm"
#include "unordered_map"
#include "unordered_set"
#include "queue"
#include "string"
#include "stack"
#include "map"
#include "set"
#include "functional"

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
