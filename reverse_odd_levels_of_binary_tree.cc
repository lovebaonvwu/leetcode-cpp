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
  TreeNode* reverseOddLevels(TreeNode* root) {
    vector<TreeNode*> q{root};
    int level = 0;

    while (!q.empty() && q[0]->left) {
      vector<TreeNode*> tmp;
      for (auto node : q) {
        tmp.insert(tmp.end(), {node->left, node->right});
      }

      if (++level % 2 != 0) {
        for (int i = 0; i < tmp.size() / 2; ++i) {
          swap(tmp[i]->val, tmp[tmp.size() - i - 1]->val);
        }
      }

      swap(q, tmp);
    }

    return root;
  }
};
// Runtime: 266 ms, faster than 28.57%
// Memory Usage: 75.7 MB, less than 14.29%
// 2022.9.19 at 奥盛大厦