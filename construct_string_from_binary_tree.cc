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
  string tree2str(TreeNode* t) {
    if (!t) {
      return "";
    }

    string ans = dfs(t);

    return ans.substr(1, ans.size() - 2);
  }

  string dfs(TreeNode* t) {
    if (!t)
      return "";

    string ans = "(";

    ans += to_string(t->val);

    if (!t->left && t->right) {
      ans += "()";
      ans += dfs(t->right);
    } else {
      ans += dfs(t->left);
      ans += dfs(t->right);
    }

    ans += ")";

    return ans;
  }
};  // 24ms

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
  string tree2str(TreeNode* t) {
    if (!t) {
      return "";
    }

    stack<TreeNode*> stk;
    unordered_set<TreeNode*> visited;

    string ans;
    ans += to_string(t->val);

    if (t->right) {
      stk.push(t->right);

      if (!t->left) {
        ans += "()";
      }
    }

    if (t->left) {
      stk.push(t->left);
    }

    while (!stk.empty()) {
      TreeNode* node = stk.top();

      if (visited.count(node)) {
        stk.pop();
        ans += ")";
      } else {
        visited.insert(node);

        ans += "(";
        ans += to_string(node->val);

        if (node->right) {
          stk.push(node->right);

          if (!node->left) {
            ans += "()";
          }
        }

        if (node->left) {
          stk.push(node->left);
        }
      }
    }

    return ans;
  }
};  // 24ms