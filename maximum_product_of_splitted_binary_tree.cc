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
  long long ans = 0;
  long long total = 0;

 public:
  int maxProduct(TreeNode* root) {
    total = dfs(root);

    dfs(root);

    return ans % ((int)1e9 + 7);
  }

  int dfs(TreeNode* root) {
    if (!root) {
      return 0;
    }

    int sum = root->val;

    sum += dfs(root->left);
    sum += dfs(root->right);

    ans = max(ans, (total - sum) * sum);

    return sum;
  }
};
// Runtime: 120 ms, faster than 62.80%
// Memory Usage: 77.3 MB, less than 89.24%
// 2021.8.19 at 奥盛大厦