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
  bool isValidBST(TreeNode* root) { return isValid(root, nullptr, nullptr); }

  bool isValid(TreeNode* root, TreeNode* min, TreeNode* max) {
    if (!root) {
      return true;
    }

    if (min && root->val <= min->val) {
      return false;
    }

    if (max && root->val >= max->val) {
      return false;
    }

    return isValid(root->left, min, root) && isValid(root->right, root, max);
  }
};
// Runtime: 8 ms, faster than 98.58%
// Memory Usage: 20.5 MB, less than 97.92%

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
  vector<int> vals;

 public:
  bool isValidBST(TreeNode* root) {
    dfs(root);

    for (int i = 1; i < vals.size(); ++i) {
      if (vals[i] <= vals[i - 1]) {
        return false;
      }
    }

    return true;
  }

  void dfs(TreeNode* root) {
    if (!root) {
      return;
    }

    dfs(root->left);

    vals.push_back(root->val);

    dfs(root->right);
  }
};
// Runtime: 12 ms, faster than 89.40%
// Memory Usage: 20.9 MB, less than 25.00%

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
  bool isValidBST(TreeNode* root) {
    stack<TreeNode*> stk;
    vector<int> vals;

    TreeNode* cur = root;

    while (!stk.empty() || cur) {
      while (cur) {
        stk.push(cur);
        cur = cur->left;
      }

      TreeNode* node = stk.top();
      stk.pop();

      vals.push_back(node->val);

      cur = node->right;
    }

    for (int i = 1; i < vals.size(); ++i) {
      if (vals[i] <= vals[i - 1]) {
        return false;
      }
    }

    return true;
  }
};
// Runtime: 12 ms, faster than 89.40%
// Memory Usage: 20.8 MB, less than 47.92%