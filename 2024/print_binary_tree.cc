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
  vector<vector<string>> printTree(TreeNode* root) {
    function<int(TreeNode*)> dfs = [&](TreeNode* root) -> int {
      if (!root)
        return 0;

      return max(dfs(root->left), dfs(root->right)) + 1;
    };

    int height = dfs(root);

    int m = height;
    int n = pow(2, m) - 1;

    vector<vector<string>> ans(m, vector<string>(n));

    queue<tuple<TreeNode*, int, int>> q;
    q.push({root, 0, (n - 1) / 2});

    while (!q.empty()) {
      int cnt = q.size();

      while (cnt-- > 0) {
        auto [node, r, c] = q.front();
        q.pop();

        ans[r][c] = to_string(node->val);

        if (node->left) {
          q.push({node->left, r + 1, c - pow(2, m - 1 - r - 1)});
        }

        if (node->right) {
          q.push({node->right, r + 1, c + pow(2, m - 1 - r - 1)});
        }
      }
    }

    return ans;
  }
};
// 0 ms
// 10.87 MB