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
  map<int, vector<pair<int, int>>> mp;

 public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    dfs(root, 0, 0);

    vector<vector<int>> ans;
    for (auto m : mp) {
      sort(m.second.begin(), m.second.end());

      vector<int> partial;
      for (auto p : m.second) {
        partial.push_back(p.second);
      }

      ans.push_back(partial);
    }

    return ans;
  }

  void dfs(TreeNode* root, int x, int y) {
    if (!root) {
      return;
    }

    mp[x].push_back({y, root->val});

    dfs(root->left, x - 1, y + 1);
    dfs(root->right, x + 1, y + 1);
  }
};
// Runtime: 4 ms, faster than 93.71%
// Memory Usage: 13.3 MB, less than 55.24%