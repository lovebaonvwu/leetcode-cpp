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
  int max_freq;
  unordered_map<int, vector<int>> mp;
  unordered_map<int, int> freq;

 public:
  vector<int> findFrequentTreeSum(TreeNode* root) {
    dfs(root);

    return mp[max_freq];
  }

  int dfs(TreeNode* root) {
    if (!root) {
      return 0;
    }

    root->val += dfs(root->left);
    root->val += dfs(root->right);

    ++freq[root->val];

    if (freq[root->val] >= max_freq) {
      max_freq = freq[root->val];
      mp[max_freq].push_back(root->val);
    }

    return root->val;
  }
};
// Runtime: 16 ms, faster than 91.23%
// Memory Usage: 24.5 MB, less than 73.54%
// 2022.3.23 at 奥盛大厦