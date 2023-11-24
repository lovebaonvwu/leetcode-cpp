/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  bool checkTree(TreeNode* root) {
    return root->val == (root->left->val + root->right->val);
  }
};
// Runtime: 3 ms, faster than 100.00%
// Memory Usage: 12.6 MB, less than 100.00%
// 2022.4.12 at 奥盛大厦