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
  int longestZigZag(TreeNode* root) {
    int left = 0, right = 0, ans = 0;

    dfs(root, left, right, ans);

    return ans;
  }

  void dfs(TreeNode* root, int left, int right, int& ans) {
    if (!root) {
      return;
    }

    ans = max(ans, left);
    ans = max(ans, right);

    dfs(root->left, 0, left + 1, ans);
    dfs(root->right, right + 1, 0, ans);
  }
};
// Runtime: 148 ms, faster than 90.84%
// Memory Usage: 94.1 MB, less than 83.52%
// 2022.3.3 at 奥盛大厦