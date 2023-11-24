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
  int findSecondMinimumValue(TreeNode* root) {
    long first = LONG_MAX;
    long second = LONG_MAX;

    dfs(root, first, second);

    return second == LONG_MAX ? -1 : second;
  }

  void dfs(TreeNode* root, long& first, long& second) {
    if (!root) {
      return;
    }

    if (root->val < first) {
      second = first;
      first = root->val;
    } else if (root->val < second && root->val > first) {
      second = root->val;
    }

    dfs(root->left, first, second);
    dfs(root->right, first, second);
  }
};  // 0ms