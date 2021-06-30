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
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* ans;

    dfs(root, p, q, &ans);

    return ans;
  }

  bool dfs(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode** ans) {
    if (!root) {
      return false;
    }

    auto left = dfs(root->left, p, q, ans);
    auto right = dfs(root->right, p, q, ans);

    if (left && right) {
      *ans = root;
    } else if (left && (root->val == p->val || root->val == q->val)) {
      *ans = root;
    } else if (right && (root->val == p->val || root->val == q->val)) {
      *ans = root;
    }

    return left || right || root->val == p->val || root->val == q->val;
  }
};
// Runtime: 16 ms, faster than 71.23%
// Memory Usage: 14.4 MB, less than 27.40%