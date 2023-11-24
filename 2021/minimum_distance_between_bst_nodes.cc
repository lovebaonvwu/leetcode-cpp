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
  int ans = INT_MAX;
  int prev = -1;

 public:
  int minDiffInBST(TreeNode* root) {
    if (root->left) {
      minDiffInBST(root->left);
    }

    if (prev > -1) {
      ans = min(ans, root->val - prev);
    }
    prev = root->val;

    if (root->right) {
      minDiffInBST(root->right);
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 11 MB, less than 100.00%

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
  int minDiffInBST(TreeNode* root) {
    vector<int> vals;

    dfs(root, vals);

    int ans = INT_MAX;

    for (int i = 1; i < vals.size(); ++i) {
      ans = min(ans, vals[i] - vals[i - 1]);
    }

    return ans;
  }

  void dfs(TreeNode* root, vector<int>& vals) {
    if (!root) {
      return;
    }

    dfs(root->left, vals);

    vals.push_back(root->val);

    dfs(root->right, vals);
  }
};
// Runtime: 4 ms, faster than 70.23%
// Memory Usage: 11.5 MB, less than 45.45%