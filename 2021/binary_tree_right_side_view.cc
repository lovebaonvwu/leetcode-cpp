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
  vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;

    if (!root) {
      return ans;
    }

    queue<TreeNode*> q;
    q.push(root);
    int cnt = 1;
    vector<int> level;

    while (!q.empty()) {
      while (cnt) {
        TreeNode* node = q.front();
        q.pop();
        --cnt;

        level.push_back(node->val);

        if (node->left) {
          q.push(node->left);
        }

        if (node->right) {
          q.push(node->right);
        }
      }

      ans.push_back(level.back());
      level.clear();

      cnt = q.size();
    }

    return ans;
  }
};

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
  vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;

    if (!root) {
      return ans;
    }

    queue<TreeNode*> q;
    q.push(root);
    int cnt = 1;
    int rightVal = 0;

    while (!q.empty()) {
      cnt = q.size();

      while (cnt--) {
        TreeNode* node = q.front();
        q.pop();

        rightVal = node->val;

        if (node->left) {
          q.push(node->left);
        }

        if (node->right) {
          q.push(node->right);
        }
      }

      ans.push_back(rightVal);
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 11.8 MB, less than 72.35%

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
  vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;

    if (!root) {
      return ans;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      int cnt = q.size();
      int rightVal = 0;

      while (cnt--) {
        TreeNode* node = q.front();
        q.pop();

        rightVal = node->val;

        if (node->left) {
          q.push(node->left);
        }

        if (node->right) {
          q.push(node->right);
        }
      }

      ans.push_back(rightVal);
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 73.84%
// Memory Usage: 11.8 MB, less than 72.35%