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
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;

    if (!root) {
      return ans;
    }

    stack<TreeNode*> stk;
    stk.push(root);

    while (!stk.empty()) {
      TreeNode* node = stk.top();
      cout << node->val << endl;

      if (node->left) {
        stk.push(node->left);
        node->left = nullptr;
      } else {
        ans.push_back(node->val);
        stk.pop();

        if (node->right) {
          stk.push(node->right);
        }
      }
    }

    return ans;
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
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;

    dfs(root, ans);

    return ans;
  }

  void dfs(TreeNode* root, vector<int>& ans) {
    if (!root)
      return;

    if (root->left) {
      dfs(root->left, ans);
    }

    ans.push_back(root->val);

    if (root->right) {
      dfs(root->right, ans);
    }
  }
};  // 0ms