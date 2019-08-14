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
  int sumOfLeftLeaves(TreeNode* root) {
    if (!root) {
      return 0;
    }

    int sum = 0;

    dfs(root->left, sum, true);
    dfs(root->right, sum, false);

    return sum;
  }

  void dfs(TreeNode* root, int& sum, bool left) {
    if (!root) {
      return;
    }

    if (!root->left && !root->right && left) {
      sum += root->val;
      return;
    }

    dfs(root->left, sum, true);
    dfs(root->right, sum, false);
  }
};  // 4ms