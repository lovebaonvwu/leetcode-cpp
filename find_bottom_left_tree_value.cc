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
  int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> q;

    q.push(root);

    int ans;
    while (!q.empty()) {
      TreeNode* node = q.front();
      q.pop();

      ans = node->val;
      if (node->right) {
        q.push(node->right);
      }

      if (node->left) {
        q.push(node->left);
      }
    }

    return ans;
  }
};
// Runtime: 16 ms, faster than 63.20%
// Memory Usage: 20.7 MB, less than 100.00%

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
  int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> q;

    q.push(root);

    int ans;
    while (!q.empty()) {
      size_t cnt = q.size();

      bool flag = true;
      while (cnt-- > 0) {
        TreeNode* node = q.front();
        q.pop();

        if (flag) {
          ans = node->val;
          flag = false;
        }

        if (node->left) {
          q.push(node->left);
        }

        if (node->right) {
          q.push(node->right);
        }
      }
    }

    return ans;
  }
};
// Runtime: 12 ms, faster than 89.61%
// Memory Usage: 20.9 MB, less than 62.50%