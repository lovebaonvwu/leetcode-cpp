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
  int ans = 0;

 public:
  int findTilt(TreeNode* root) {
    dfs(root);

    return ans;
  }

  int dfs(TreeNode* root) {
    if (!root) {
      return 0;
    }

    int left = dfs(root->left);
    int right = dfs(root->right);

    ans += abs(left - right);

    return root->val + left + right;
  }
};
// Runtime: 20 ms, faster than 88.22%
// Memory Usage: 24.2 MB, less than 6.20%