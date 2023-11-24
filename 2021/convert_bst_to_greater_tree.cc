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
  int sum = 0;

 public:
  TreeNode* convertBST(TreeNode* root) {
    if (!root) {
      return nullptr;
    }

    convertBST(root->right);

    root->val += sum;

    sum = root->val;

    convertBST(root->left);

    return root;
  }
};
// Runtime: 52 ms, faster than 43.33%
// Memory Usage: 34.5 MB, less than 99.67%