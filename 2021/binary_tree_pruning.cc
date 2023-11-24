/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  TreeNode* pruneTree(TreeNode* root) {
    if (!root) {
      return nullptr;
    }

    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);

    return !root->left && !root->right && root->val == 0 ? nullptr : root;
  }
};
// Runtime: 4 ms, faster than 68.51%
// Memory Usage: 11.1 MB, less than 7.14%