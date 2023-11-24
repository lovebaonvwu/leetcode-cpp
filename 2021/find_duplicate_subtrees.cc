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
  unordered_map<string, int> mp;
  vector<TreeNode*> ans;

 public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    dfs(root);

    return ans;
  }

  string dfs(TreeNode* root) {
    if (!root) {
      return "#";
    }

    string key =
        to_string(root->val) + "," + dfs(root->left) + "," + dfs(root->right);

    if (++mp[key] == 2) {
      ans.push_back(root);
    }

    return key;
  }
};
// Runtime: 24 ms, faster than 97.10%
// Memory Usage: 48.7 MB, less than 57.65%
// 2021.11.5 at 奥盛大厦