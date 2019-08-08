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
  bool isCousins(TreeNode* root, int x, int y) {
    int x_depth = 0, y_depth = 0;
    TreeNode* x_parent;
    TreeNode* y_parent;

    x_parent = dfs(root, x, 0, x_depth);
    y_parent = dfs(root, y, 0, y_depth);

    return x_depth == y_depth && x_parent && y_parent &&
           x_parent->val != y_parent->val;
  }

  TreeNode* dfs(TreeNode* root, int val, int depth, int& d) {
    if (!root) {
      return nullptr;
    }

    if (root->left && root->left->val == val) {
      d = depth;
      return root;
    }

    if (root->right && root->right->val == val) {
      d = depth;
      return root;
    }

    TreeNode* p;

    p = dfs(root->left, val, depth + 1, d);

    if (p) {
      return p;
    }

    p = dfs(root->right, val, depth + 1, d);

    if (p) {
      return p;
    }

    return nullptr;
  }
};  // 0ms

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
  bool isCousins(TreeNode* root, int x, int y) {
    int x_depth = 0, y_depth = 0;
    TreeNode* x_parent;
    TreeNode* y_parent;

    x_parent = dfs(nullptr, root, x, 0, x_depth);
    y_parent = dfs(nullptr, root, y, 0, y_depth);

    return x_depth == y_depth && x_parent && y_parent &&
           x_parent->val != y_parent->val;
  }

  TreeNode* dfs(TreeNode* parent, TreeNode* root, int val, int depth, int& d) {
    if (!root) {
      return nullptr;
    }

    if (root->val == val) {
      d = depth;
      return parent;
    }

    TreeNode* p;

    p = dfs(root, root->left, val, depth + 1, d);

    if (p) {
      return p;
    }

    p = dfs(root, root->right, val, depth + 1, d);

    if (p) {
      return p;
    }

    return nullptr;
  }
};  // 4ms