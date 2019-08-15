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
  string smallestFromLeaf(TreeNode* root) {
    string ans = "";

    dfs(root, "", ans);

    return ans;
  }

  void dfs(TreeNode* root, string s, string& ans) {
    if (!root) {
      return;
    }

    s = char(root->val + 'a') + s;
    if (!root->left && !root->right) {
      ans = ans == "" ? s : min(ans, s);

      return;
    }

    dfs(root->left, s, ans);
    dfs(root->right, s, ans);
  }
};  // 8ms