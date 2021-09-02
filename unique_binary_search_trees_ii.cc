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
  vector<TreeNode*> generateTrees(int n) { return dfs(1, n); }

  vector<TreeNode*> dfs(int start, int end) {
    vector<TreeNode*> ret;

    if (start > end) {
      return {nullptr};
    }

    if (start == end) {
      return {new TreeNode(start)};
    }

    for (int i = start; i <= end; ++i) {
      auto left = dfs(start, i - 1);
      auto right = dfs(i + 1, end);

      for (auto& l : left) {
        for (auto& r : right) {
          TreeNode* root = new TreeNode(i);
          root->left = l;
          root->right = r;

          ret.push_back(root);
        }
      }
    }

    return ret;
  }
};
// Runtime: 20 ms, faster than 39.86%
// Memory Usage: 15.4 MB, less than 82.20%
// 2021.9.2 at 奥盛大厦