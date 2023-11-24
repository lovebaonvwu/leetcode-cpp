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
  int distributeCoins(TreeNode* root) {
    dfs(root);

    return ans;
  }

  int dfs(TreeNode* root) {
    if (!root) {
      return 0;
    }

    int left = dfs(root->left);
    int right = dfs(root->right);

    ans += abs(left) + abs(right);

    return root->val + left + right - 1;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 13.9 MB, less than 85.66%