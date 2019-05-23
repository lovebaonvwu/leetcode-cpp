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
  int sumNumbers(TreeNode* root) {
    int sum = 0;
    int temp = 0;

    sumNumber(root, temp, sum);

    return sum;
  }

  void sumNumber(TreeNode* root, int temp, int& sum) {
    if (!root) {
      return;
    }

    temp = temp * 10 + root->val;
    if (!root->left && !root->right) {
      sum += temp;
    }

    sumNumber(root->left, temp, sum);
    sumNumber(root->right, temp, sum);
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
  int sumNumbers(TreeNode* root) {
    int sum = 0;

    sumNumber(root, 0, sum);

    return sum;
  }

  void sumNumber(TreeNode* root, int temp, int& sum) {
    if (!root) {
      return;
    }

    temp = temp * 10 + root->val;
    if (!root->left && !root->right) {
      sum += temp;
    }

    sumNumber(root->left, temp, sum);
    sumNumber(root->right, temp, sum);
  }
};  // 8ms