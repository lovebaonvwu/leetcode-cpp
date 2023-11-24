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
  int ans;

 public:
  int countPairs(TreeNode* root, int distance) {
    dfs(root, distance);

    return ans;
  }

  vector<int> dfs(TreeNode* root, int d) {
    if (!root) {
      return {};
    }

    auto left = dfs(root->left, d);
    auto right = dfs(root->right, d);

    if (left.empty() && right.empty()) {
      return {1};
    }

    for (auto l : left) {
      for (auto r : right) {
        if (l + r <= d) {
          ++ans;
        }
      }
    }

    vector<int> v;
    for (auto l : left) {
      v.push_back(l + 1);
    }

    for (auto r : right) {
      v.push_back(r + 1);
    }

    return v;
  }
};
// Runtime: 140 ms, faster than 25.12%
// Memory Usage: 37.8 MB, less than 34.58%