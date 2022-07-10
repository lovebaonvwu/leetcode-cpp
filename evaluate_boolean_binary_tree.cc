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
  bool evaluateTree(TreeNode* root) {
    if (root->val == 0 || root->val == 1) {
      return root->val;
    }

    return root->val == 2
               ? evaluateTree(root->left) || evaluateTree(root->right)
               : evaluateTree(root->left) && evaluateTree(root->right);
  }
};
// Runtime: 17 ms, faster than 100.00%
// Memory Usage: 14.9 MB, less than 100.00%
// 2022.7.10 at 茗筑美嘉