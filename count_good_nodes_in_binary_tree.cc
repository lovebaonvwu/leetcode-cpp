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
  int ans;

 public:
  int goodNodes(TreeNode* root) {
    inorder(root, root->val);

    return ans;
  }

  void inorder(TreeNode* root, int mx) {
    if (!root) {
      return;
    }

    if (root->val >= mx) {
      ++ans;
    }

    mx = max(mx, root->val);

    inorder(root->left, mx);
    inorder(root->right, mx);
  }
};
// Runtime: 208 ms, faster than 78.47%
// Memory Usage: 86.6 MB, less than 100.00%

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
  int ans;

 public:
  int goodNodes(TreeNode* root) {
    inorder(root, root->val);

    return ans;
  }

  void inorder(TreeNode* root, int mx) {
    if (!root) {
      return;
    }

    if (root->val >= mx) {
      ++ans;
      mx = root->val;
    }

    inorder(root->left, mx);
    inorder(root->right, mx);
  }
};
// Runtime: 212 ms, faster than 74.06%
// Memory Usage: 86.3 MB, less than 100.00%

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
  int goodNodes(TreeNode* root, int mx = INT_MIN) {
    return root
               ? (root->val >= mx) + goodNodes(root->left, max(mx, root->val)) +
                     goodNodes(root->right, max(mx, root->val))
               : 0;
  }
};
// Runtime: 212 ms, faster than 74.06%
// Memory Usage: 86.6 MB, less than 100.00%

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
  int goodNodes(TreeNode* root) {
    queue<pair<TreeNode*, int>> q;

    q.push({root, root->val});

    int ans = 0;
    while (!q.empty()) {
      auto [root, mx] = q.front();
      q.pop();

      if (root->val >= mx) {
        ++ans;
        mx = root->val;
      }

      if (root->left) {
        q.push({root->left, mx});
      }

      if (root->right) {
        q.push({root->right, mx});
      }
    }

    return ans;
  }
};
// Runtime: 212 ms, faster than 74.06%
// Memory Usage: 90.3 MB, less than 100.00%