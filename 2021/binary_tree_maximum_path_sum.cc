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
  int ans = INT_MIN;

 public:
  int maxPathSum(TreeNode* root) {
    postTraversal(root);

    return ans;
  }

  int postTraversal(TreeNode* root) {
    if (!root) {
      return 0;
    }

    int left = postTraversal(root->left);
    int right = postTraversal(root->right);

    int val = root->val;

    val += left > 0 ? left : 0;
    val += right > 0 ? right : 0;

    ans = max(ans, val);

    return root->val + max(0, max(left, right));
  }
};
// Runtime: 32 ms, faster than 85.98%
// Memory Usage: 28.9 MB, less than 42.01%

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
  int ans = INT_MIN;

 public:
  int maxPathSum(TreeNode* root) {
    postTraversal(root);

    return ans;
  }

  int postTraversal(TreeNode* root) {
    if (!root) {
      return 0;
    }

    int left = postTraversal(root->left);
    int right = postTraversal(root->right);

    int val = root->val;

    val += max(0, left);
    val += max(0, right);

    ans = max(ans, val);

    return root->val + max(0, max(left, right));
  }
};
// Runtime: 36 ms, faster than 62.71%
// Memory Usage: 28.8 MB, less than 65.58%