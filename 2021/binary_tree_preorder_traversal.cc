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
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;

    if (!root) {
      return ans;
    }

    stack<TreeNode*> stk;
    stk.push(root);

    while (!stk.empty()) {
      TreeNode* node = stk.top();
      stk.pop();

      ans.push_back(node->val);

      if (node->right) {
        stk.push(node->right);
      }

      if (node->left) {
        stk.push(node->left);
      }
    }

    return ans;
  }
};

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
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;

    dfs(root, ans);

    return ans;
  }

  void dfs(TreeNode* root, vector<int>& ans) {
    if (!root) {
      return;
    }

    ans.push_back(root->val);
    dfs(root->left, ans);
    dfs(root->right, ans);
  }
};