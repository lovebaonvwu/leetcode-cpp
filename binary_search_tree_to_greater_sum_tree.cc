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
  TreeNode* bstToGst(TreeNode* root) {
    int sum = 0;

    dfs(root, sum);

    return root;
  }

  void dfs(TreeNode* root, int& sum) {
    if (!root) {
      return;
    }

    dfs(root->right, sum);
    sum += root->val;
    root->val = sum;
    dfs(root->left, sum);
  }
};  // 0ms