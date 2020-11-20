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
  int minCameraCover(TreeNode* root) {
    dfs(root, nullptr);

    return ans == 0 ? 1 : ans;
  }

  void dfs(TreeNode* root, TreeNode* parent) {
    if (!root) {
      return;
    }

    dfs(root->left, root);
    dfs(root->right, root);

    if (root->left && root->left->val == 0 ||
        root->right && root->right->val == 0) {
      ++ans;
      root->val = 1;
    } else if (root->left && root->left->val == 1 ||
               root->right && root->right->val == 1) {
      root->val = 2;
    } else if (!parent) {
      ++ans;
      root->val = 1;
    }
  }
};
// Runtime: 16 ms, faster than 57.50%
// Memory Usage: 21.6 MB, less than 49.17%

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
  int minCameraCover(TreeNode* root) {
    dfs(root, nullptr);

    return ans;
  }

  void dfs(TreeNode* root, TreeNode* parent) {
    if (!root) {
      return;
    }

    dfs(root->left, root);
    dfs(root->right, root);

    if (root->left && root->left->val == 0 ||
        root->right && root->right->val == 0) {
      ++ans;
      root->val = 1;
    } else if (root->left && root->left->val == 1 ||
               root->right && root->right->val == 1) {
      root->val = 2;
    } else if (!parent) {
      ++ans;
      root->val = 1;
    }
  }
};
// Runtime: 12 ms, faster than 78.85%
// Memory Usage: 21.6 MB, less than 73.12%

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
  int minCameraCover(TreeNode* root) { return (dfs(root) < 1 ? 1 : 0) + ans; }

  int dfs(TreeNode* root) {
    if (!root) {
      return 2;
    }

    int left = dfs(root->left);
    int right = dfs(root->right);

    if (left == 0 || right == 0) {
      ++ans;
      return 1;
    } else if (left == 1 || right == 1) {
      return 2;
    }

    return 0;
  }
};
// Runtime: 12 ms, faster than 78.85%
// Memory Usage: 21.5 MB, less than 73.12%