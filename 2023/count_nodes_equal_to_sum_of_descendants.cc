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
  int equalToDescendants(TreeNode* root) {
    dfs(root);

    return ans;
  }

  long long dfs(TreeNode* root) {
    if (!root) {
      return 0;
    }

    long long left = dfs(root->left);
    long long right = dfs(root->right);

    if (root->val == left + right) {
      ++ans;
    }

    return left + right + root->val;
  }
};
// Runtime 356 ms
// Memory 200.2 MB
// 2023.1.29 at 茗筑美嘉