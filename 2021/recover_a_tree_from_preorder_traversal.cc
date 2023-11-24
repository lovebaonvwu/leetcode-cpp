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
  TreeNode* recoverFromPreorder(string S) {
    vector<TreeNode*> tree(1000);

    for (int i = 0; i < S.size();) {
      int d = 0;
      while (S[i] == '-') {
        ++d;
        ++i;
      }

      int val = 0;
      while (isdigit(S[i])) {
        val = val * 10 + (S[i] - '0');
        ++i;
      }

      TreeNode* node = new TreeNode(val);
      tree[d] = node;

      if (d == 0) {
        continue;
      }

      if (!tree[d - 1]->left) {
        tree[d - 1]->left = node;
      } else {
        tree[d - 1]->right = node;
      }
    }

    return tree[0];
  }
};
// Runtime: 16 ms, faster than 90.23%
// Memory Usage: 20.5 MB, less than 37.50%