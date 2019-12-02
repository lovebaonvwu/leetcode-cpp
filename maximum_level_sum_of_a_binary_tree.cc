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
  int maxLevelSum(TreeNode* root) {
    queue<TreeNode*> q;

    q.push(root);

    int mx = INT_MIN;
    int lv = 1, ans = lv;

    while (!q.empty()) {
      int n = q.size();

      int sum = 0;

      while (n-- > 0) {
        TreeNode* node = q.front();
        q.pop();

        sum += node->val;

        if (node->left) {
          q.push(node->left);
        }

        if (node->right) {
          q.push(node->right);
        }
      }

      if (sum > mx) {
        mx = sum;
        ans = lv;
      }

      ++lv;
    }

    return ans;
  }
};
// Runtime: 216 ms, faster than 93.14%
// Memory Usage: 72.7 MB, less than 100.00%

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
  vector<int> sum;

 public:
  int maxLevelSum(TreeNode* root) {
    dfs(root, 1);

    int ans = 0;
    int mx = INT_MIN;
    for (int i = 0; i < sum.size(); ++i) {
      if (sum[i] > sum[ans]) {
        ans = i;
      }
    }

    return ans + 1;
  }

  void dfs(TreeNode* root, int lvl) {
    if (!root) {
      return;
    }

    if (sum.size() < lvl) {
      sum.resize(lvl);
    }

    sum[lvl - 1] += root->val;
    dfs(root->left, lvl + 1);
    dfs(root->right, lvl + 1);
  }
};
// Runtime: 224 ms, faster than 79.15%
// Memory Usage: 70.3 MB, less than 100.00%

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
  vector<int> sum;

 public:
  int maxLevelSum(TreeNode* root) {
    dfs(root, 1);

    int ans = 0;
    int mx = INT_MIN;
    for (int i = 0; i < sum.size(); ++i) {
      if (sum[i] > mx) {
        ans = i;
        mx = sum[i];
      }
    }

    return ans + 1;
  }

  void dfs(TreeNode* root, int lvl) {
    if (!root) {
      return;
    }

    if (sum.size() < lvl) {
      sum.resize(lvl);
    }

    sum[lvl - 1] += root->val;
    dfs(root->left, lvl + 1);
    dfs(root->right, lvl + 1);
  }
};
// Runtime: 240 ms, faster than 27.71%
// Memory Usage: 70.2 MB, less than 100.00%

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
  int maxLevelSum(TreeNode* root) {
    queue<TreeNode*> q;

    q.push(root);

    int ans = 1;
    int mx = INT_MIN;
    int lv = 0;

    while (!q.empty()) {
      int n = q.size();

      int sum = 0;

      while (n-- > 0) {
        TreeNode* node = q.front();
        q.pop();

        sum += node->val;

        if (node->left) {
          q.push(node->left);
        }

        if (node->right) {
          q.push(node->right);
        }
      }

      ++lv;

      if (sum > mx) {
        mx = sum;
        ans = lv;
      }
    }

    return ans;
  }
};
// Runtime: 248 ms, faster than 14.16%
// Memory Usage: 72.8 MB, less than 100.00%