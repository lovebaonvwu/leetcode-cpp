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
  int widthOfBinaryTree(TreeNode* root) {
    queue<TreeNode*> q;

    q.push(root);

    int ans = 0;

    while (!q.empty()) {
      int cnt = q.size();

      vector<int*> lvl;

      while (cnt-- > 0) {
        auto node = q.front();
        q.pop();

        lvl.push_back(node ? &node->val : nullptr);

        if (node) {
          q.push(node->left);
          q.push(node->right);
        } else {
          q.push(nullptr);
          q.push(nullptr);
        }
      }

      int i = -1;
      int j = -1;

      for (int k = 0; k < lvl.size(); ++k) {
        if (lvl[k]) {
          i = k;
          break;
        }
      }

      for (int k = lvl.size() - 1; k >= 0; --k) {
        if (lvl[k]) {
          j = k;
          break;
        }
      }

      if (i == -1) {
        break;
      }

      ans = max(ans, j - i + 1);
    }

    return ans;
  }
};
// Time Limit Exceeded

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
  int widthOfBinaryTree(TreeNode* root) {
    queue<TreeNode*> q;

    q.push(root);

    int ans = 0;

    while (!q.empty()) {
      int cnt = q.size();

      int s = -1;
      int e = -1;
      int p = -1;

      while (cnt-- > 0) {
        auto node = q.front();
        q.pop();

        if (node && s < 0) {
          ++s;
          ++e;
          ++p;
        } else if (node && s > -1) {
          ++e;
          p = e;
        } else if (!node && s > -1) {
          ++e;
        }

        if (node) {
          q.push(node->left);
          q.push(node->right);
        } else {
          q.push(nullptr);
          q.push(nullptr);
        }
      }

      if (s == -1) {
        break;
      }

      ans = max(ans, p - s + 1);
    }

    return ans;
  }
};
// Time Limit Exceeded

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
  int widthOfBinaryTree(TreeNode* root) {
    vector<unsigned int> lefts;

    return dfs(root, 1, 0, lefts);
  }

 private:
  unsigned int dfs(TreeNode* n,
                   unsigned int id,
                   int d,
                   vector<unsigned int>& lefts) {
    if (!n)
      return 0;
    if (d >= lefts.size())
      lefts.push_back(id);
    return max({id + 1 - lefts[d], dfs(n->left, id * 2, d + 1, lefts),
                dfs(n->right, id * 2 + 1, d + 1, lefts)});
  }
};
// Runtime: 12 ms, faster than 46.19%
// Memory Usage: 16.3 MB, less than 25.31%

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
  int widthOfBinaryTree(TreeNode* root) {
    queue<pair<TreeNode*, unsigned int>> q;

    q.push({root, 1});

    int ans = 0;

    while (!q.empty()) {
      unsigned int left = q.front().second;
      unsigned int right = left;

      for (int i = 0, n = q.size(); i < n; ++i) {
        auto p = q.front();
        q.pop();

        right = p.second;

        if (p.first->left) {
          q.push({p.first->left, right * 2});
        }
        if (p.first->right) {
          q.push({p.first->right, right * 2 + 1});
        }
      }

      ans = max(static_cast<int>(right - left + 1), ans);
    }

    return ans;
  }
};
// Runtime: 12 ms, faster than 46.19%
// Memory Usage: 15.7 MB, less than 81.46%