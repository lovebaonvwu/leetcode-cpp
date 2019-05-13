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
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> vec1;
    vector<int> vec2;

    dfs(root1, vec1);
    dfs(root2, vec2);

    return vec1 == vec2;
  }

  void dfs(TreeNode* root, vector<int>& vec) {
    if (!root)
      return;

    if (!root->left && !root->right) {
      vec.push_back(root->val);
      return;
    }

    dfs(root->left, vec);
    dfs(root->right, vec);
  }
};