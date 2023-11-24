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
  int maxAncestorDiff(TreeNode* root) {
    dfs(root, root->val, root->val);

    return ans;
  }

  void dfs(TreeNode* root, int max_val, int min_val) {
    if (!root) {
      return;
    }

    ans = max(ans, abs(root->val - max_val));
    ans = max(ans, abs(root->val - min_val));

    dfs(root->left, max(max_val, root->val), min(min_val, root->val));
    dfs(root->right, max(max_val, root->val), min(min_val, root->val));
  }
};
// Runtime: 8 ms, faster than 65.52%
// Memory Usage: 11.3 MB, less than 5.86%

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
  int maxAncestorDiff(TreeNode* root) {
    dfs(root, root->val, root->val);

    return ans;
  }

  void dfs(TreeNode* root, int max_val, int min_val) {
    if (!root) {
      return;
    }

    ans = max(ans, abs(root->val - max_val));
    ans = max(ans, abs(root->val - min_val));

    max_val = max(max_val, root->val);
    min_val = min(min_val, root->val);

    dfs(root->left, max_val, min_val);
    dfs(root->right, max_val, min_val);
  }
};
// Runtime: 4 ms, faster than 96.88%
// Memory Usage: 11.4 MB, less than 5.86%

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
  int maxAncestorDiff(TreeNode* root) {
    return dfs(root, root->val, root->val);
  }

  int dfs(TreeNode* root, int max_val, int min_val) {
    if (!root) {
      return max_val - min_val;
    }

    max_val = max(max_val, root->val);
    min_val = min(min_val, root->val);

    return max(dfs(root->left, max_val, min_val),
               dfs(root->right, max_val, min_val));
  }
};
// Runtime: 8 ms, faster than 65.52%
// Memory Usage: 11.4 MB, less than 5.86%