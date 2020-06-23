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
  int countNodes(TreeNode* root) {
    int ans = 0;

    inorderTraverse(root, ans);

    return ans;
  }

  void inorderTraverse(TreeNode* root, int& cnt) {
    if (!root) {
      return;
    }

    ++cnt;

    inorderTraverse(root->left, cnt);
    inorderTraverse(root->right, cnt);
  }
};
// Runtime: 40 ms, faster than 82.93%
// Memory Usage: 30.9 MB, less than 64.42%

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
  int countNodes(TreeNode* root) {
    if (!root) {
      return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};
// Runtime: 40 ms, faster than 82.93%
// Memory Usage: 30.8 MB, less than 75.23%

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
  int countNodes(TreeNode* root) {
    if (!root) {
      return 0;
    }

    int lh = 0;
    int rh = 0;

    TreeNode* left = root;
    TreeNode* right = root;

    while (left) {
      ++lh;
      left = left->left;
    }

    while (right) {
      ++rh;
      right = right->right;
    }

    if (lh == rh) {
      return pow(2, lh) - 1;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};
// Runtime: 44 ms, faster than 64.00%
// Memory Usage: 31.2 MB, less than 13.47%