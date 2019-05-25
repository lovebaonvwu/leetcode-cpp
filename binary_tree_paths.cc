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
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;
    string path = "";

    dfs(root, ans, path);

    return ans;
  }

  void dfs(TreeNode* root, vector<string>& ans, string& path) {
    if (!root) {
      return;
    }

    string temp = to_string(root->val);

    if (!root->left && !root->right) {
      path += temp;
      ans.push_back(path.substr(0, path.size()));

      for (int i = 0; i < temp.size(); ++i) {
        path.pop_back();
      }

      return;
    }

    temp += "->";
    path += temp;

    dfs(root->left, ans, path);
    dfs(root->right, ans, path);

    for (int i = 0; i < temp.size(); ++i) {
      path.pop_back();
    }
  }
};