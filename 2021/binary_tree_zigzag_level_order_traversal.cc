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
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;

    if (!root) {
      return ans;
    }

    bool l2r = true;

    deque<TreeNode*> de;
    vector<int> level;

    de.push_back(root);

    int cnt = 1;

    while (!de.empty()) {
      while (cnt) {
        TreeNode* node = l2r ? de.front() : de.back();
        l2r ? de.pop_front() : de.pop_back();
        --cnt;

        level.push_back(node->val);

        if (l2r) {
          if (node->left) {
            de.push_back(node->left);
          }

          if (node->right) {
            de.push_back(node->right);
          }
        } else {
          if (node->right) {
            de.push_front(node->right);
          }

          if (node->left) {
            de.push_front(node->left);
          }
        }
      }

      l2r = !l2r;

      ans.push_back(level);

      cnt = de.size();

      level.clear();
    }

    return ans;
  }
};