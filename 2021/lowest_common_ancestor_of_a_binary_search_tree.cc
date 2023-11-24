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
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return p->val < q->val ? preorderTraversal(root, p->val, q->val)
                           : preorderTraversal(root, q->val, p->val);
  }

  TreeNode* preorderTraversal(TreeNode* root, int p, int q) {
    if (root->val == p || root->val == q) {
      return root;
    }

    if (root->val > p && root->val < q) {
      return root;
    }

    if (root->val < p) {
      return preorderTraversal(root->right, p, q);
    } else {
      return preorderTraversal(root->left, p, q);
    }
  }
};
// Runtime: 28 ms, faster than 93.03%
// Memory Usage: 23.8 MB, less than 24.75%