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
  int pseudoPalindromicPaths(TreeNode* root) {
    vector<int> v(10);

    dfs(root, v);

    return ans;
  }

  void dfs(TreeNode* root, vector<int> v) {
    if (!root) {
      return;
    }

    ++v[root->val];

    if (!root->left && !root->right) {
      int oddValue = 0;
      for (int i = 0; i < v.size(); ++i) {
        if (v[i] & 1) {
          ++oddValue;
        }
      }

      if (oddValue <= 1) {
        ++ans;
      }

      return;
    }

    dfs(root->left, v);
    dfs(root->right, v);
  }
};
// Runtime: 456 ms, faster than 47.46%
// Memory Usage: 249.7 MB, less than 100.00%

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
  int pseudoPalindromicPaths(TreeNode* root) { return dfs(root, 0); }

  int dfs(TreeNode* root, int cnt) {
    if (!root) {
      return 0;
    }

    cnt ^= 1 << (root->val - 1);
    int res = dfs(root->left, cnt) + dfs(root->right, cnt);

    if (!root->left && !root->right && (cnt & (cnt - 1)) == 0) {
      ++res;
    }

    return res;
  }
};
// Runtime: 228 ms, faster than 93.25%
// Memory Usage: 107.3 MB, less than 100.00%