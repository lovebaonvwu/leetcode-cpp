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
  bool hasPathSum(TreeNode* root, int sum) {
    if (!root)
      return false;

    return pathSum(root, sum);
  }

  bool pathSum(TreeNode* root, int sum) {
    if (!root) {
      return false;
    }

    sum -= root->val;

    if (!root->left && !root->right) {
      return sum == 0;
    }

    if (!root->right) {
      return pathSum(root->left, sum);
    }

    if (!root->left) {
      return pathSum(root->right, sum);
    }

    return pathSum(root->left, sum) || pathSum(root->right, sum);
  }
};  // 8ms

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
  bool hasPathSum(TreeNode* root, int sum) {
    if (!root)
      return false;
    sum -= root->val;

    if (!root->left && !root->right) {
      return sum == 0;
    }

    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
  }
};  // 16ms