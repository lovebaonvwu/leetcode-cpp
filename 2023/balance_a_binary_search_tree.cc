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
 public:
  TreeNode* balanceBST(TreeNode* root) {
    vector<TreeNode*> nodes;
    function<void(TreeNode*)> dfs = [&](TreeNode* root) -> void {
      if (!root)
        return;
      dfs(root->left);
      root->left = nullptr;
      nodes.push_back(root);
      dfs(root->right);
      root->right = nullptr;
    };

    function<TreeNode*(int, int)> build = [&](int l, int r) -> TreeNode* {
      if (l > r)
        return nullptr;
      int m = (l + r) / 2;
      TreeNode* node = nodes[m];
      node->left = build(l, m - 1);
      node->right = build(m + 1, r);

      return node;
    };

    dfs(root);
    return build(0, nodes.size() - 1);
  }
};
// 61ms
// 47.57MB