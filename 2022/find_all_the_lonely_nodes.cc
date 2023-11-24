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
  vector<int> getLonelyNodes(TreeNode* root) {
    dfs(root);

    return ans;
  }

  void dfs(TreeNode* root) {
    if (!root) {
      return;
    }

    if (root->left && !root->right) {
      ans.push_back(root->left->val);
    }

    if (root->right && !root->left) {
      ans.push_back(root->right->val);
    }

    dfs(root->left);
    dfs(root->right);
  }
};
// Runtime 23 ms
// Memory 20.3 MB
// 2022.11.28 at 茗筑美嘉