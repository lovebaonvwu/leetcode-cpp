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
  int deepest = 0;
  TreeNode* ans;

 public:
  TreeNode* lcaDeepestLeaves(TreeNode* root) {
    dfs(root, 0);

    return ans;
  }

  int dfs(TreeNode* root, int deep) {
    deepest = max(deepest, deep);

    if (!root) {
      return deep;
    }

    int left = dfs(root->left, deep + 1);
    int right = dfs(root->right, deep + 1);

    if (left == deepest && right == deepest) {
      ans = root;
    }

    return max(left, right);
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 21.2 MB, less than 89.13%