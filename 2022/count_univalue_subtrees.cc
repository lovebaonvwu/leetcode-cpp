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
  int ans = 0;

 public:
  int countUnivalSubtrees(TreeNode* root) {
    dfs(root);

    return ans;
  }

  bool dfs(TreeNode* root) {
    if (!root) {
      return true;
    }

    bool left = dfs(root->left);
    bool right = dfs(root->right);

    if (left && right) {
      if (root->left && root->val != root->left->val) {
        return false;
      }

      if (root->right && root->val != root->right->val) {
        return false;
      }

      ++ans;
    }

    return left && right;
  }
};
// Runtime 7 ms
// Memory 16.7 MB
// 2022.12.10 at 茗筑美嘉