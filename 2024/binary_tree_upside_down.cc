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
  TreeNode* upsideDownBinaryTree(TreeNode* root) {
    if (!root)
      return nullptr;

    TreeNode* new_root = upsideDownBinaryTree(root->left);
    if (!new_root)
      return root;

    root->left->left = root->right;
    root->left->right = root;

    root->left = nullptr;
    root->right = nullptr;

    return new_root;
  }
};
// 3 ms
// 12.20 MB