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
  int sumRootToLeaf(TreeNode* root) {
    int sum = 0;

    doSum(root, sum, 0);

    return sum;
  }

  void doSum(TreeNode* root, int& sum, int tmp) {
    if (!root) {
      return;
    }

    tmp = tmp * 2 + root->val;
    if (!root->left && !root->right) {
      sum += tmp;
      return;
    }

    doSum(root->left, sum, tmp);
    doSum(root->right, sum, tmp);
  }
};  // 8ms