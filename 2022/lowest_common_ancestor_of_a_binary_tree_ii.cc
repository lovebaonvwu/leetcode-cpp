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
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* ans = nullptr;
    dfs(root, ans, p->val, q->val);

    return ans;
  }

  bool dfs(TreeNode* root, TreeNode*& ans, int p, int q) {
    if (!root) {
      return false;
    }

    bool left = dfs(root->left, ans, p, q);
    bool right = dfs(root->right, ans, p, q);

    if (left && right) {
      ans = root;
      return true;
    } else if (left && (root->val == p || root->val == q)) {
      ans = root;
      return true;
    } else if (right && (root->val == p || root->val == q)) {
      ans = root;
      return true;
    } else if (root->val == p || root->val == q) {
      return true;
    }

    return left || right;
  }
};
// Runtime 176 ms
// Memory 61.8 MB
// 2022.12.9 at 奥盛大厦