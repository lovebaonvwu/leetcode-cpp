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
  int diameterOfBinaryTree(TreeNode* root) {
    treeHeight(root);

    return ans;
  }

  int treeHeight(TreeNode* root) {
    if (!root) {
      return 0;
    }

    int leftHeight = treeHeight(root->left) + 1;
    int rightHeight = treeHeight(root->right) + 1;

    ans = max(leftHeight + rightHeight - 2, ans);

    return max(leftHeight, rightHeight);
  }
};
// Runtime: 4 ms, faster than 99.48%
// Memory Usage: 19.8 MB, less than 88.89%