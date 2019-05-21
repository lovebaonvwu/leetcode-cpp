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
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> ans;
    vector<int> stk;

    findPath(root, sum, ans, stk);

    return ans;
  }

  void findPath(TreeNode* root,
                int sum,
                vector<vector<int>>& ans,
                vector<int>& stk) {
    if (!root) {
      return;
    }
    sum -= root->val;
    stk.push_back(root->val);

    if (!root->left && !root->right && sum == 0) {
      ans.push_back(stk);
    }

    findPath(root->left, sum, ans, stk);
    findPath(root->right, sum, ans, stk);

    stk.pop_back();
  }
};