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
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;

    if (!root) {
      return ans;
    }

    stack<TreeNode*> stk;
    stk.push(root);

    while (!stk.empty()) {
      TreeNode* node = stk.top();

      ans.push_back(node->val);

      stk.pop();

      if (node->left) {
        stk.push(node->left);
      }

      if (node->right) {
        stk.push(node->right);
      }
    }

    int i = 0;
    int j = ans.size() - 1;

    while (i < j) {
      swap(ans[i++], ans[j--]);
    }

    return ans;
  }
};  // 4ms

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
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;

    dfs(root, ans);

    return ans;
  }

  void dfs(TreeNode* root, vector<int>& ans) {
    if (!root) {
      return;
    }

    dfs(root->left, ans);
    dfs(root->right, ans);

    ans.push_back(root->val);
  }
};  // 0ms