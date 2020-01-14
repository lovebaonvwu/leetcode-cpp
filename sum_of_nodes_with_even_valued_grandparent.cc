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
  int sum = 0;

 public:
  int sumEvenGrandparent(TreeNode* root) {
    dfs(root, 1, 1);

    return sum;
  }

  void dfs(TreeNode* root, int p, int gp) {
    if (!root) {
      return;
    }

    if (gp % 2 == 0) {
      sum += root->val;
    }

    dfs(root->left, root->val, p);
    dfs(root->right, root->val, p);
  }
};

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
  int sum = 0;

 public:
  int sumEvenGrandparent(TreeNode* root) {
    dfs(root);

    return sum;
  }

  void dfs(TreeNode* root) {
    if (!root) {
      return;
    }

    if (root->val % 2 == 0) {
      if (root->left && root->left->left) {
        sum += root->left->left->val;
      }

      if (root->left && root->left->right) {
        sum += root->left->right->val;
      }

      if (root->right && root->right->left) {
        sum += root->right->left->val;
      }

      if (root->right && root->right->right) {
        sum += root->right->right->val;
      }
    }

    dfs(root->left);
    dfs(root->right);
  }
};
// Runtime: 44 ms, faster than 50.00%
// Memory Usage: 31.4 MB, less than 100.00%