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
  int averageOfSubtree(TreeNode* root) {
    int cnt = 0;
    dfs(root, cnt);

    return ans;
  }

  int dfs(TreeNode* root, int& cnt) {
    if (!root) {
      cnt = 0;
      return 0;
    }

    int leftcnt = 0, rightcnt = 0;
    int sum = root->val + dfs(root->left, leftcnt) + dfs(root->right, rightcnt);

    if (sum / (leftcnt + rightcnt + 1) == root->val) {
      ++ans;
    }

    cnt = 1 + leftcnt + rightcnt;

    return sum;
  }
};
// Runtime: 17 ms, faster than 50.00%
// Memory Usage: 12 MB, less than 12.50%
// 2022.5.8 at 茗筑美嘉