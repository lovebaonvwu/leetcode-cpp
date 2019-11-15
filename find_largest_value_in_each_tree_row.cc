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
  vector<int> largestValues(TreeNode* root) {
    if (!root) {
      return {};
    }

    vector<int> ans;

    queue<TreeNode*> q;

    q.push(root);

    while (!q.empty()) {
      int sz = q.size();

      int largest = INT_MIN;
      while (sz-- > 0) {
        TreeNode* node = q.front();
        q.pop();

        largest = max(largest, node->val);

        if (node->left) {
          q.push(node->left);
        }

        if (node->right) {
          q.push(node->right);
        }
      }

      ans.push_back(largest);
    }

    return ans;
  }
};
// Runtime: 16 ms, faster than 77.77%
// Memory Usage: 20.9 MB, less than 100.00%

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
  vector<int> largestValues(TreeNode* root) {
    vector<int> ans;

    dfs(root, 0, ans);

    return ans;
  }

  void dfs(TreeNode* root, int level, vector<int>& ans) {
    if (!root) {
      return;
    }

    while (ans.size() <= level) {
      ans.push_back(INT_MIN);
    }

    dfs(root->left, level + 1, ans);
    ans[level] = max(root->val, ans[level]);
    dfs(root->right, level + 1, ans);
  }
};
// Runtime: 20 ms, faster than 44.59%
// Memory Usage: 21 MB, less than 94.74%