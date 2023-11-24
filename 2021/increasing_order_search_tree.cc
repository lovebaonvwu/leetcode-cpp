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
  TreeNode* increasingBST(TreeNode* root) {
    stack<TreeNode*> stk;

    TreeNode dummy(0);
    TreeNode* prev = &dummy;

    TreeNode* cur = root;

    while (!stk.empty() || cur) {
      while (cur) {
        stk.push(cur);
        cur = cur->left;
      }

      cur = stk.top();
      stk.pop();

      cur->left = nullptr;

      prev->right = cur;
      prev = prev->right;

      cur = cur->right;
    }

    return dummy.right;
  }
};
// Runtime: 32 ms, faster than 91.65%
// Memory Usage: 16.5 MB, less than 60.00%

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
  vector<TreeNode*> nodes;

 public:
  TreeNode* increasingBST(TreeNode* root) {
    dfs(root);

    TreeNode* prev = nodes[0];
    for (int i = 1; i < nodes.size(); ++i) {
      prev->left = nullptr;
      prev->right = nodes[i];

      prev = nodes[i];
    }

    prev->left = nullptr;
    prev->right = nullptr;

    return nodes[0];
  }

  void dfs(TreeNode* root) {
    if (!root) {
      return;
    }

    dfs(root->left);

    nodes.push_back(root);

    dfs(root->right);
  }
};
// Runtime: 36 ms, faster than 77.63%
// Memory Usage: 18.7 MB, less than 50.00%