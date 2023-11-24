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
  unordered_map<int, vector<int>> g;

 public:
  int amountOfTime(TreeNode* root, int start) {
    dfs(root);

    queue<int> q;
    q.push(start);

    unordered_set<int> visited;

    int ans = 0;
    while (!q.empty()) {
      int cnt = q.size();
      while (cnt-- > 0) {
        int node = q.front();
        q.pop();
        visited.insert(node);

        for (auto next : g[node]) {
          if (visited.find(next) != visited.end()) {
            continue;
          }

          q.push(next);
        }
      }
      ++ans;
    }

    return ans - 1;
  }

  void dfs(TreeNode* root) {
    if (!root) {
      return;
    }

    if (root->left) {
      g[root->val].push_back(root->left->val);
      g[root->left->val].push_back(root->val);
    }

    if (root->right) {
      g[root->val].push_back(root->right->val);
      g[root->right->val].push_back(root->val);
    }

    dfs(root->left);
    dfs(root->right);
  }
};
// Runtime: 694 ms, faster than 57.14%
// Memory Usage: 185.7 MB, less than 57.14%
// 2022.8.24 at 奥盛大厦