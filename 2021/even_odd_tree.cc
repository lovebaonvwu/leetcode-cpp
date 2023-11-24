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
 public:
  bool isEvenOddTree(TreeNode* root) {
    queue<TreeNode*> q;

    q.push(root);

    bool evenLevel = true;

    while (!q.empty()) {
      int cnt = q.size();

      int* prev = nullptr;

      while (cnt-- > 0) {
        TreeNode* node = q.front();
        q.pop();

        if (evenLevel) {
          if (!(node->val & 1)) {
            return false;
          }

          if (prev && node->val <= *prev) {
            return false;
          }
        } else {
          if (node->val & 1) {
            return false;
          }

          if (prev && node->val >= *prev) {
            return false;
          }
        }

        prev = &node->val;

        if (node->left) {
          q.push(node->left);
        }

        if (node->right) {
          q.push(node->right);
        }
      }

      evenLevel = !evenLevel;
    }

    return true;
  }
};
// Runtime: 360 ms, faster than 93.31%
// Memory Usage: 152.5 MB, less than 91.82%

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
  bool isEvenOddTree(TreeNode* root) { return dfs(root, 0); }

  bool dfs(TreeNode* root, int lvl) {
    if (!root) {
      return true;
    }

    if ((lvl & 1) && (root->val & 1)) {
      return false;
    }

    if (!(lvl & 1) && !(root->val & 1)) {
      return false;
    }

    if (mp.find(lvl) != mp.end()) {
      if ((lvl & 1) && root->val >= mp[lvl]) {
        return false;
      }

      if (!(lvl & 1) && root->val <= mp[lvl]) {
        return false;
      }
    }

    mp[lvl] = root->val;

    return dfs(root->left, lvl + 1) && dfs(root->right, lvl + 1);
  }
};
// Runtime: 456 ms, faster than 76.66%
// Memory Usage: 185.9 MB, less than 18.98%