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
  TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    int d;

    return dfs(root, d);
  }

  TreeNode* dfs(TreeNode* root, int& d) {
    if (!root) {
      d = 0;
      return nullptr;
    }

    int ld;
    int rd;

    TreeNode* left = dfs(root->left, ld);
    TreeNode* right = dfs(root->right, rd);

    d = max(ld, rd) + 1;

    if (ld == rd) {
      return root;
    } else if (ld > rd) {
      return left;
    } else {
      return right;
    }
  }
};
// Runtime: 4 ms, faster than 85.25%
// Memory Usage: 15 MB, less than 37.21%