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
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) {
      return new TreeNode(val);
    }

    TreeNode* cur = root;
    while (true) {
      if (val < cur->val) {
        if (!cur->left) {
          cur->left = new TreeNode(val);
          break;
        }
        cur = cur->left;
      } else {
        if (!cur->right) {
          cur->right = new TreeNode(val);
          break;
        }
        cur = cur->right;
      }
    }

    return root;
  }
};
// Runtime: 116 ms, faster than 83.90%
// Memory Usage: 48.9 MB, less than 6.25%

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
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    TreeNode** cur = &root;

    while (*cur) {
      if (val < (*cur)->val) {
        cur = &(*cur)->left;
      } else {
        cur = &(*cur)->right;
      }
    }

    *cur = new TreeNode(val);

    return root;
  }
};
// Runtime: 124 ms, faster than 68.96%
// Memory Usage: 49.4 MB, less than 6.25%

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
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) {
      root = new TreeNode(val);
    } else if (val < root->val) {
      root->left = insertIntoBST(root->left, val);
    } else {
      root->right = insertIntoBST(root->right, val);
    }

    return root;
  }
};
// Runtime: 124 ms, faster than 68.96%
// Memory Usage: 49.2 MB, less than 6.25%

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
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (val < root->val) {
      if (!root->left) {
        root->left = new TreeNode(val);
      } else {
        insertIntoBST(root->left, val);
      }
    } else {
      if (!root->right) {
        root->right = new TreeNode(val);
      } else {
        insertIntoBST(root->right, val);
      }
    }
    return root;
  }
};
// Runtime: 136 ms, faster than 24.64%
// Memory Usage: 49.6 MB, less than 6.25%