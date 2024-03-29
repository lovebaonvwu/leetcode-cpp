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
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root) {
      return false;
    }

    if (dfs(root, subRoot)) {
      return true;
    }

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }

  bool dfs(TreeNode* root, TreeNode* subRoot) {
    if (root == subRoot) {
      return true;
    }

    if (!root || !subRoot) {
      return false;
    }

    if (subRoot->val != root->val) {
      return false;
    }

    return dfs(root->left, subRoot->left) && dfs(root->right, subRoot->right);
  }
};
// Runtime: 53 ms, faster than 12.99%
// Memory Usage: 28.9 MB, less than 56.54%
// 2022.3.24 at 奥盛大厦