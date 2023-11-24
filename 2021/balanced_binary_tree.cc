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
  bool isBalanced(TreeNode* root) {
    int height;

    return balanced(root, height);
  }

  bool balanced(TreeNode* root, int& height) {
    if (!root)
      return true;

    int lr = 0, rh = 0;

    if (balanced(root->left, lr) && balanced(root->right, rh)) {
      height = (lr > rh ? lr : rh) + 1;

      return (lr - rh <= 1) && (lr - rh >= -1);
    }

    return false;
  }
};  // 12ms

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
  bool isBalanced(TreeNode* root) {
    if (!root)
      return true;

    int lh = treeHeight(root->left);
    int rh = treeHeight(root->right);
    bool sub_tree_is_balanced = (lh - rh <= 1) && (lh - rh >= -1);

    return sub_tree_is_balanced && isBalanced(root->left) &&
           isBalanced(root->right);
  }

  int treeHeight(TreeNode* root) {
    if (!root)
      return 0;

    int lh = treeHeight(root->left);
    int rh = treeHeight(root->right);

    return 1 + (lh > rh ? lh : rh);
  }
};  // 16ms