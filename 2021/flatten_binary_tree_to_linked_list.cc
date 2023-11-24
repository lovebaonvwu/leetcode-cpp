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
  void flatten(TreeNode* root) {
    while (root) {
      if (root->left) {
        TreeNode* temp = root->left;
        while (temp->right) {
          temp = temp->right;
        }

        temp->right = root->right;
        root->right = root->left;

        root->left = nullptr;
      }

      root = root->right;
    }
  }
}; // 4ms

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
  void flatten(TreeNode* root) {
    TreeNode* prev = nullptr;

    dfsFlatten(root, prev);
  }

  void dfsFlatten(TreeNode* root, TreeNode*& prev) {
    if (!root) {
      return;
    }

    dfsFlatten(root->right, prev);
    dfsFlatten(root->left, prev);

    root->left = nullptr;
    root->right = prev;

    prev = root;
  }
}; // 8ms