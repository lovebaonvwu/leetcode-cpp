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
  bool findTarget(TreeNode* root, int k) {
    if (!root) {
      return false;
    }

    set<int> st;

    return dfs(root, st, k);
  }

  bool dfs(TreeNode* root, set<int>& st, int& t) {
    if (!root) {
      return false;
    }

    if (dfs(root->left, st, t)) {
      return true;
    }

    if (st.count(t - root->val)) {
      return true;
    }

    st.insert(root->val);

    return dfs(root->right, st, t);
  }
};
// Runtime: 40 ms, faster than 74.60%
// Memory Usage: 26.4 MB, less than 30.00%

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
  bool findTarget(TreeNode* root, int k) {
    if (!root) {
      return false;
    }

    unordered_set<int> st;

    stack<TreeNode*> stk;

    stk.push(root);

    while (!stk.empty()) {
      TreeNode* node = stk.top();
      stk.pop();

      if (st.count(k - node->val)) {
        return true;
      }

      st.insert(node->val);

      if (node->left) {
        stk.push(node->left);
      }

      if (node->right) {
        stk.push(node->right);
      }
    }

    return false;
  }
};
// Runtime: 44 ms, faster than 54.13%
// Memory Usage: 26.9 MB, less than 30.00%

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
  bool findTarget(TreeNode* root, int k) {
    unordered_set<int> st;

    return dfs(root, st, k);
  }

  bool dfs(TreeNode* root, unordered_set<int>& st, int& target) {
    if (!root) {
      return false;
    }

    if (st.count(target - root->val)) {
      return true;
    }

    st.insert(root->val);

    return dfs(root->left, st, target) || dfs(root->right, st, target);
  }
};
// Runtime: 48 ms, faster than 35.02%
// Memory Usage: 26.1 MB, less than 40.00%