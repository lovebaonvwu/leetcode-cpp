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
  vector<vector<int>> ans;

 public:
  vector<vector<int>> findLeaves(TreeNode* root) {
    getHeight(root);

    return ans;
  }

  int getHeight(TreeNode* root) {
    if (!root) {
      return -1;
    }

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    int curHeight = 1 + max(leftHeight, rightHeight);
    if (curHeight == ans.size()) {
      ans.push_back({});
    }

    ans[curHeight].push_back(root->val);

    return curHeight;
  }
};
// Runtime 10 ms
// Memory 8.9 MB
// 2022.11.22 at 茗筑美嘉