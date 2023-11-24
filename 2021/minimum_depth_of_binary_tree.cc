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
  int minDepth(TreeNode* root) {
    if (!root)
      return 0;

    if (!root->left && !root->right)
      return 1;

    if (root->left && !root->right) {
      return minDepth(root->left) + 1;
    }

    if (root->right && !root->left) {
      return minDepth(root->right) + 1;
    }

    int left = minDepth(root->left);
    int right = minDepth(root->right);

    return (left < right ? left : right) + 1;
  }
};