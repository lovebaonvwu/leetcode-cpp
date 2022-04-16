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
  int maxSumBST(TreeNode* root) {
    int ans = 0;
    dfs(root, ans);
    return ans;
  }

  tuple<int, int, int, bool> dfs(TreeNode* root, int& ans) {
    if (!root) {
      return {INT_MAX, INT_MIN, 0, true};
    }

    auto [lmin, lmax, lsum, lvalid] = dfs(root->left, ans);
    auto [rmin, rmax, rsum, rvalid] = dfs(root->right, ans);

    bool valid = lvalid && rvalid && root->val > lmax && root->val < rmin;

    int sum = valid ? lsum + rsum + root->val : -1;
    ans = max(ans, sum);

    return {min(lmin, root->val), max(rmax, root->val), sum, valid};
  }
};
// Runtime: 179 ms, faster than 85.90%
// Memory Usage: 105.3 MB, less than 57.78%
// 2022.4.16 at 奥盛大厦