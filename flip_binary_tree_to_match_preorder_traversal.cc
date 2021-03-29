/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  vector<int> ans;

 public:
  vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
    int p = 0;

    return dfs(root, voyage, p) ? ans : vector<int>{-1};
  }

  bool dfs(TreeNode* root, const vector<int>& v, int& p) {
    if (!root) {
      return true;
    }

    if (root->val != v[p++]) {
      return false;
    }

    if (root->left && root->left->val != v[p]) {
      ans.push_back(root->val);

      swap(root->left, root->right);
    }

    return dfs(root->left, v, p) && dfs(root->right, v, p);
  }
};
// Runtime: 4 ms, faster than 74.64%
// Memory Usage: 13.6 MB, less than 80.71%