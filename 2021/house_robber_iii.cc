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
  int rob(TreeNode* root) {
    if (!root) {
      return 0;
    }

    return dfs(root);
  }

  int dfs(TreeNode* root) {
    if (!root) {
      return 0;
    }

    int sum = 0;

    if (root->left) {
      sum += dfs(root->left);
    }

    if (root->right) {
      sum += dfs(root->right);
    }

    int sum2 = 0;
    if (root->left && root->left->left) {
      sum2 += root->left->left->val;
    }

    if (root->left && root->left->right) {
      sum2 += root->left->right->val;
    }

    if (root->right && root->right->left) {
      sum2 += root->right->left->val;
    }

    if (root->right && root->right->right) {
      sum2 += root->right->right->val;
    }

    root->val = max(root->val + sum2, sum);

    return root->val;
  }
};
// Runtime: 20 ms, faster than 78.05%
// Memory Usage: 22.4 MB, less than 5.41%

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
  int rob(TreeNode* root) {
    if (!root) {
      return 0;
    }

    int sum = 0;

    if (root->left) {
      sum += rob(root->left);
    }

    if (root->right) {
      sum += rob(root->right);
    }

    int sum2 = 0;
    if (root->left && root->left->left) {
      sum2 += root->left->left->val;
    }

    if (root->left && root->left->right) {
      sum2 += root->left->right->val;
    }

    if (root->right && root->right->left) {
      sum2 += root->right->left->val;
    }

    if (root->right && root->right->right) {
      sum2 += root->right->right->val;
    }

    root->val = max(root->val + sum2, sum);

    return root->val;
  }
};
// Runtime: 12 ms, faster than 97.92%
// Memory Usage: 22.5 MB, less than 5.41%