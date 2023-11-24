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
  int getMinimumDifference(TreeNode* root) {
    stack<TreeNode*> stk;

    int ans = INT_MAX;
    int prev = -1;

    stk.push(root);

    while (!stk.empty()) {
      TreeNode* node = stk.top();

      if (node->left) {
        stk.push(node->left);

        node->left = nullptr;
      } else {
        stk.pop();

        ans = prev == -1 ? INT_MAX : min(ans, node->val - prev);

        prev = node->val;

        if (node->right) {
          stk.push(node->right);
        }
      }
    }

    return ans;
  }
};  // 16ms

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
  int ans = INT_MAX;

 public:
  int getMinimumDifference(TreeNode* root) {
    int prev = -1;

    dfs(root, prev);

    return ans;
  }

  void dfs(TreeNode* root, int& prev) {
    if (!root) {
      return;
    }

    dfs(root->left, prev);

    if (prev > -1) {
      ans = min(ans, root->val - prev);
    }

    prev = root->val;

    dfs(root->right, prev);
  }
};  // 16ms