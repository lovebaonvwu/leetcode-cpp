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
  TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      int cnt = q.size();

      while (cnt-- > 0) {
        auto cur = q.front();
        q.pop();

        if (cur->val == u->val) {
          if (cnt > 0) {
            return q.front();
          } else {
            return nullptr;
          }
        }

        if (cur->left) {
          q.push(cur->left);
        }

        if (cur->right) {
          q.push(cur->right);
        }
      }
    }

    return nullptr;
  }
};
// 137 ms
// 85.16 MB
