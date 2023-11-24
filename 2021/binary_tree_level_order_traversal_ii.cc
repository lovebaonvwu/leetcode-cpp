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
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> ans;

    if (!root) {
      return ans;
    }

    queue<TreeNode*> q;
    vector<int> level;

    q.push(root);
    int cnt = 1;

    while (!q.empty()) {
      while (cnt) {
        TreeNode* node = q.front();
        q.pop();
        --cnt;

        level.push_back(node->val);

        if (node->left) {
          q.push(node->left);
        }

        if (node->right) {
          q.push(node->right);
        }
      }

      ans.push_back(level);
      level.clear();

      cnt = q.size();
    }

    int i = 0;
    int j = ans.size() - 1;

    while (i < j) {
      swap(ans[i++], ans[j--]);
    }

    return ans;
  }
};