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
static constexpr int kMaxN = 20 + 1;
static array<vector<TreeNode*>, kMaxN> memo;

class Solution {
 public:
  vector<TreeNode*> allPossibleFBT(int n) { return dfs(n); }

  vector<TreeNode*>& dfs(int n) {
    if (memo[n].size() > 0) {
      return memo[n];
    }

    vector<TreeNode*>& ret = memo[n];

    if (n % 2 == 0) {
      return ret = {};
    }

    if (n == 1) {
      return ret = {new TreeNode(0)};
    }

    for (int i = 1; i < n; i += 2) {
      for (auto& l : dfs(i)) {
        for (auto& r : dfs(n - 1 - i)) {
          TreeNode* root = new TreeNode(0);
          root->left = l;
          root->right = r;

          ret.push_back(root);
        }
      }
    }

    return ret;
  }
};
// Runtime: 80 ms, faster than 91.73%
// Memory Usage: 27.4 MB, less than 100.00%
// 2021.8.6 at 奥盛大厦

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
  vector<TreeNode*> allPossibleFBT(int n) {
    if (n % 2 == 0) {
      return {};
    }

    vector<vector<TreeNode*>> dp(n + 1);
    dp[1].push_back({new TreeNode(0)});

    for (int i = 3; i <= n; i += 2) {
      for (int j = 1; j < i; j += 2) {
        for (auto& l : dp[j]) {
          for (auto& r : dp[i - 1 - j]) {
            TreeNode* root = new TreeNode(0);
            root->left = l;
            root->right = r;

            dp[i].push_back(root);
          }
        }
      }
    }

    return dp[n];
  }
};
// Runtime: 100 ms, faster than 48.00%
// Memory Usage: 27.7 MB, less than 98.39%
// 2021.8.6 at 奥盛大厦