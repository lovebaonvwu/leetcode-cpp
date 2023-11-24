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
  bool isUnivalTree(TreeNode* root) {
    unordered_set<int> st;

    dfs(root, st);

    return st.size() == 1;
  }

  void dfs(TreeNode* root, unordered_set<int>& st) {
    if (!root) {
      return;
    }

    st.insert(root->val);
    dfs(root->left, st);
    dfs(root->right, st);
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
  bool isUnivalTree(TreeNode* root) {
    unordered_set<int> st;

    stack<TreeNode*> stk;
    stk.push(root);

    while (!stk.empty()) {
      TreeNode* tmp = stk.top();
      stk.pop();

      st.insert(tmp->val);

      if (tmp->left) {
        stk.push(tmp->left);
      }

      if (tmp->right) {
        stk.push(tmp->right);
      }
    }

    return st.size() == 1;
  }
};  // 4ms