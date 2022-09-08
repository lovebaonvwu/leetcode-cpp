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
  int cnt = 0;
  int N;

 public:
  bool btreeGameWinningMove(TreeNode* root, int n, int x) {
    N = n;
    dfs(root, x);

    return cnt > (n / 2);
  }

  int dfs(TreeNode* root, int x) {
    if (!root) {
      return 0;
    }

    int left = dfs(root->left, x);
    int right = dfs(root->right, x);

    if (root->val == x) {
      cnt = max(left, max(right, N - left - right - 1));
    }

    return 1 + left + right;
  }
};
// Runtime: 4 ms, faster than 71.84%
// Memory Usage: 10.7 MB, less than 61.91%
// 2022.9.8 at 奥盛大厦