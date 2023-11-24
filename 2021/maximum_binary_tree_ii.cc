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
  TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
    if (!root) {
      return new TreeNode(val);
    }

    if (val > root->val) {
      TreeNode* ans = new TreeNode(val);
      ans->left = root;
      return ans;
    }

    root->right = insertIntoMaxTree(root->right, val);

    return root;
  }
};
// Runtime: 8 ms, faster than 44.41%
// Memory Usage: 14.1 MB, less than 26.44%