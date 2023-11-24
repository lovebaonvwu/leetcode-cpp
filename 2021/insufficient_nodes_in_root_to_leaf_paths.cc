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
  TreeNode* sufficientSubset(TreeNode* root, int limit) {
    return dfs(root, 0, limit);
  }

  TreeNode* dfs(TreeNode* root, int sum, int limit) {
    if (!root) {
      return nullptr;
    }

    if (!root->left && !root->right) {
      if (root->val + sum < limit) {
        return nullptr;
      } else {
        return root;
      }
    }

    bool hasLeft = root->left ? true : false;
    bool hasRight = root->right ? true : false;

    root->left = dfs(root->left, sum + root->val, limit);
    root->right = dfs(root->right, sum + root->val, limit);

    if (!root->left && !root->right && (hasLeft || hasRight)) {
      return nullptr;
    }

    return root;
  }
};
// Runtime: 44 ms, faster than 68.56%
// Memory Usage: 33.1 MB, less than 58.08%
// 2021.11.3 at 奥盛大厦

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
  TreeNode* sufficientSubset(TreeNode* root, int limit) {
    return dfs(root, 0, limit);
  }

  TreeNode* dfs(TreeNode* root, int sum, int limit) {
    if (!root) {
      return nullptr;
    }

    if (!root->left && !root->right) {
      if (root->val + sum < limit) {
        return nullptr;
      } else {
        return root;
      }
    }

    root->left = dfs(root->left, sum + root->val, limit);
    root->right = dfs(root->right, sum + root->val, limit);

    return root->left == root->right ? nullptr : root;
  }
};
// Runtime: 52 ms, faster than 41.02%
// Memory Usage: 33.1 MB, less than 19.46%
// 2021.11.3 at 奥盛大厦

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
  TreeNode* sufficientSubset(TreeNode* root, int limit) {
    return dfs(root, 0, limit);
  }

  TreeNode* dfs(TreeNode* root, int sum, int limit) {
    if (!root) {
      return nullptr;
    }

    if (!root->left && !root->right) {
      if (root->val + sum < limit) {
        return nullptr;
      } else {
        return root;
      }
    }

    root->left = dfs(root->left, sum + root->val, limit);
    root->right = dfs(root->right, sum + root->val, limit);

    if (!root->left && !root->right) {
      return nullptr;
    }

    return root;
  }
};
// Runtime: 40 ms, faster than 82.93%
// Memory Usage: 33.1 MB, less than 58.08%
// 2021.11.3 at 奥盛大厦