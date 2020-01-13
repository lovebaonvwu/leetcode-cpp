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
  int mx = -1;
  int sum = 0;

 public:
  int deepestLeavesSum(TreeNode* root) {
    dfs(root, 0);

    return sum;
  }

  void dfs(TreeNode* root, int lvl) {
    if (!root) {
      return;
    }

    if (!root->left && !root->right) {
      if (lvl > mx) {
        mx = lvl;
        sum = root->val;
      } else if (lvl == mx) {
        sum += root->val;
      }
    } else {
      dfs(root->left, lvl + 1);
      dfs(root->right, lvl + 1);
    }
  }
};
// Runtime: 48 ms, faster than 73.07%
// Memory Usage: 31.3 MB, less than 100.00%

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
  int deepestLeavesSum(TreeNode* root) {
    int ans;

    queue<TreeNode*> q;

    q.push(root);

    while (!q.empty()) {
      size_t cnt = q.size();

      ans = 0;
      while (cnt-- > 0) {
        TreeNode* node = q.front();
        q.pop();

        ans += node->val;

        if (node->left) {
          q.push(node->left);
        }

        if (node->right) {
          q.push(node->right);
        }
      }
    }

    return ans;
  }
};
// Runtime: 52 ms, faster than 48.40%
// Memory Usage: 32 MB, less than 100.00%

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
  int deepestLeavesSum(TreeNode* root) {
    int lvl = 0;
    int mx = -1;
    int sum = 0;

    dfs(root, lvl, mx, sum);

    return sum;
  }

  void dfs(TreeNode* root, int lvl, int& mx, int& sum) {
    if (!root) {
      return;
    }

    if (!root->left && !root->right) {
      if (lvl > mx) {
        mx = lvl;
        sum = root->val;
      } else if (lvl == mx) {
        sum += root->val;
      }
    } else {
      dfs(root->left, lvl + 1, mx, sum);
      dfs(root->right, lvl + 1, mx, sum);
    }
  }
};
// Runtime: 52 ms, faster than 48.40%
// Memory Usage: 31.5 MB, less than 100.00%