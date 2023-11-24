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
  vector<double> averageOfLevels(TreeNode* root) {
    queue<TreeNode*> q;

    q.push(root);

    vector<double> ans;

    while (!q.empty()) {
      int cnt = q.size();
      int tmp = cnt;
      double sum = 0;

      while (tmp-- > 0) {
        TreeNode* node = q.front();
        q.pop();

        sum += node->val;

        if (node->left) {
          q.push(node->left);
        }

        if (node->right) {
          q.push(node->right);
        }
      }

      ans.push_back(sum / cnt);
    }

    return ans;
  }
};
// Runtime: 16 ms, faster than 91.17%
// Memory Usage: 21.7 MB, less than 88.89%

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
  vector<double> vals;
  vector<int> cnts;

 public:
  vector<double> averageOfLevels(TreeNode* root) {
    dfs(root, 0);

    for (int i = 0; i < vals.size(); ++i) {
      vals[i] /= cnts[i];
    }

    return vals;
  }

  void dfs(TreeNode* root, int lvl) {
    if (!root) {
      return;
    }

    if (vals.size() < lvl + 1) {
      vals.resize(lvl + 1);
      cnts.resize(lvl + 1);
    }

    vals[lvl] += root->val;
    ++cnts[lvl];

    dfs(root->left, lvl + 1);
    dfs(root->right, lvl + 1);
  }
};
// Runtime: 20 ms, faster than 71.51%
// Memory Usage: 21.6 MB, less than 100.00%