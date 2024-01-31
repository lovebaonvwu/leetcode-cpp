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
  int longestUnivaluePath(TreeNode* root) {
    int ans = 0;

    function<int(TreeNode*)> dfs = [&](TreeNode* root) -> int {
      if (!root)
        return 0;

      int cur = 1;
      int l = dfs(root->left);
      int r = dfs(root->right);

      if (root->left && root->val == root->left->val) {
        cur += l;
      }

      if (root->right && root->val == root->right->val) {
        cur += r;
      }

      ans = max(ans, cur);

      if (root->left && root->val == root->left->val && root->right &&
          root->val == root->right->val) {
        return max(l, r) + 1;
      } else if (root->left && root->val == root->left->val) {
        return l + 1;
      } else if (root->right && root->val == root->right->val) {
        return r + 1;
      } else {
        return 1;
      }
    };

    dfs(root);

    return ans == 0 ? ans : ans - 1;
  }
};
// 90 ms
// 70.25 MB