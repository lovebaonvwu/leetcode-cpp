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
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) {
      return nullptr;
    }

    if (root->val == key) {
      if (!root->right) {
        TreeNode* tmp = root;
        root = root->left;
        delete tmp;
      } else {
        TreeNode* cur = root->right;
        while (cur->left) {
          cur = cur->left;
        }

        cur->left = root->left;
        TreeNode* tmp = root;

        root = root->right;
        delete tmp;
      }
    } else if (key < root->val) {
      root->left = deleteNode(root->left, key);
    } else {
      root->right = deleteNode(root->right, key);
    }

    return root;
  }
};
// Runtime: 36 ms, faster than 69.49%
// Memory Usage: 15.3 MB, less than 59.04%

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
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) {
      return nullptr;
    }

    if (root->val == key) {
      if (!root->right) {
        TreeNode* left = root->left;
        delete root;

        return left;
      } else {
        TreeNode* cur = root->right;
        while (cur->left) {
          cur = cur->left;
        }

        swap(root->val, cur->val);
      }
    }

    root->left = deleteNode(root->left, key);
    root->right = deleteNode(root->right, key);

    return root;
  }
};
// Runtime: 36 ms, faster than 69.49%
// Memory Usage: 15.4 MB, less than 28.29%