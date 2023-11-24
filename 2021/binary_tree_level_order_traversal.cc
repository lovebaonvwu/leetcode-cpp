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
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    int cnt = 0;
    vector<int> level;

    if (!root) {
      return ans;
    }

    q.push(root);
    ++cnt;

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

      cnt = q.size();

      ans.push_back(level);

      level.clear();
    }

    return ans;
  }
};  // 4ms

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
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    int cnt = 0;

    if (!root) {
      return ans;
    }

    q.push(root);
    ++cnt;

    while (!q.empty()) {
      vector<int> level{};

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

      cnt = q.size();

      ans.push_back(level);
    }

    return ans;
  }
};  // 8ms