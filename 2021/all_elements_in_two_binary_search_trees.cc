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
  vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    queue<int> q1;
    queue<int> q2;

    dfs(root1, q1);
    dfs(root2, q2);

    vector<int> ans;
    while (!q1.empty() && !q2.empty()) {
      if (q1.front() < q2.front()) {
        ans.push_back(q1.front());
        q1.pop();
      } else {
        ans.push_back(q2.front());
        q2.pop();
      }
    }

    while (!q1.empty()) {
      ans.push_back(q1.front());
      q1.pop();
    }

    while (!q2.empty()) {
      ans.push_back(q2.front());
      q2.pop();
    }

    return ans;
  }

  void dfs(TreeNode* root, queue<int>& q) {
    if (!root) {
      return;
    }

    dfs(root->left, q);
    q.push(root->val);
    dfs(root->right, q);
  }
};
// Runtime: 276 ms, faster than 67.96%
// Memory Usage: 58.5 MB, less than 100.00%