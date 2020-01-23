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
  TreeNode* removeLeafNodes(TreeNode* root, int target) {
    return dfs(root, target);
  }

  TreeNode* dfs(TreeNode* root, int target) {
    if (!root) {
      return nullptr;
    }

    root->left = dfs(root->left, target);
    root->right = dfs(root->right, target);

    if (!root->left && !root->right && root->val == target) {
      root = nullptr;
    }

    return root;
  }
};
// Runtime: 36 ms, faster than 8.19%
// Memory Usage: 21.5 MB, less than 100.00%

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
  TreeNode* removeLeafNodes(TreeNode* root, int target) {
    if (!root) {
      return nullptr;
    }

    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);

    return !root->left && !root->right && root->val == target ? nullptr : root;
  }
};
// Runtime: 40 ms, faster than 8.19%
// Memory Usage: 21.4 MB, less than 100.00%