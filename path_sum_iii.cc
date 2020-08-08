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
  int pathSum(TreeNode* root, int sum) {
    if (!root) {
      return 0;
    }

    return prefixSum(root, sum, 0) + pathSum(root->left, sum) +
           pathSum(root->right, sum);
  }

  int prefixSum(TreeNode* root, int target, int sum) {
    if (!root) {
      return 0;
    }

    sum += root->val;

    return (sum == target) + prefixSum(root->left, target, sum) +
           prefixSum(root->right, target, sum);
  }
};
// Runtime: 24 ms, faster than 83.92%
// Memory Usage: 15.6 MB, less than 88.99%

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
  int ans = 0;

 public:
  int pathSum(TreeNode* root, int sum) {
    dfs(root, sum, {0});

    return ans;
  }

  void dfs(TreeNode* root, int target, vector<int> presum) {
    if (!root) {
      return;
    }

    presum.push_back(presum.back() + root->val);

    for (int i = 0; i < presum.size() - 1; ++i) {
      if (presum[presum.size() - 1] - presum[i] == target) {
        ++ans;
      }
    }

    dfs(root->left, target, presum);
    dfs(root->right, target, presum);
  }
};
// Runtime: 56 ms, faster than 19.05%
// Memory Usage: 64.4 MB, less than 7.40%

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
  int ans = 0;
  unordered_map<int, int> mp;

 public:
  int pathSum(TreeNode* root, int sum) {
    mp[0] = 1;

    dfs(root, sum, 0);

    return ans;
  }

  void dfs(TreeNode* root, int target, int presum) {
    if (!root) {
      return;
    }

    presum += root->val;
    ans += mp[presum - target];

    ++mp[presum];

    dfs(root->left, target, presum);
    dfs(root->right, target, presum);

    --mp[presum];
  }
};
// Runtime: 24 ms, faster than 83.92%
// Memory Usage: 20.6 MB, less than 19.11%