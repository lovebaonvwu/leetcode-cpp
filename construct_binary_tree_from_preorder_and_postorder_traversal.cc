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
  unordered_map<int, int> mp;

 public:
  TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    for (int i = 0; i < post.size(); ++i) {
      mp[post[i]] = i;
    }

    return dfs(pre, post, 0, pre.size() - 1, 0, post.size() - 1);
  }

  TreeNode* dfs(vector<int>& pre,
                vector<int>& post,
                int pre_start,
                int pre_end,
                int post_start,
                int post_end) {
    TreeNode* root = new TreeNode(pre[pre_start]);

    if (pre_start == pre_end) {
      return root;
    }

    int idx = mp[pre[pre_start + 1]];

    int len = idx - post_start + 1;

    root->left = dfs(pre, post, pre_start + 1, pre_start + len, post_start,
                     post_start + len - 1);

    if (idx + 1 == post_end) {
      return root;
    }

    root->right =
        dfs(pre, post, pre_start + len + 1, pre_end, idx + 1, post_end - 1);

    return root;
  }
};
// Runtime: 8 ms, faster than 96.56%
// Memory Usage: 25.7 MB, less than 77.70%