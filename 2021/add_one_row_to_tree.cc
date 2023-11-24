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
  TreeNode* addOneRow(TreeNode* root, int v, int d) {
    if (d == 1) {
      TreeNode* node = new TreeNode(v);
      node->left = root;

      return node;
    }

    queue<TreeNode*> q;
    q.push(root);
    int depth = 1;

    while (!q.empty()) {
      if (depth == d - 1) {
        break;
      }

      int cnt = q.size();

      while (cnt-- > 0) {
        auto node = q.front();
        q.pop();

        if (node->left) {
          q.push(node->left);
        }

        if (node->right) {
          q.push(node->right);
        }
      }

      ++depth;
    }

    while (!q.empty()) {
      auto* node = q.front();
      q.pop();

      TreeNode* leftNode = new TreeNode(v);
      leftNode->left = node->left;
      node->left = leftNode;

      TreeNode* rightNode = new TreeNode(v);
      rightNode->right = node->right;
      node->right = rightNode;
    }

    return root;
  }
};
// Runtime: 16 ms, faster than 90.51%
// Memory Usage: 25.1 MB, less than 30.43%

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
  TreeNode* addOneRow(TreeNode* root, int v, int d) {
    return dfs(root, v, d, 1);
  }

  TreeNode* dfs(TreeNode* root, int v, int d, int depth) {
    if (!root) {
      return nullptr;
    }

    if (d == 1) {
      return new TreeNode(v, root, nullptr);
    } else if (d - 1 == depth) {
      root->left = new TreeNode(v, root->left, nullptr);
      root->right = new TreeNode(v, nullptr, root->right);
    } else {
      root->left = dfs(root->left, v, d, depth + 1);
      root->right = dfs(root->right, v, d, depth + 1);
    }

    return root;
  }
};
// Runtime: 12 ms, faster than 98.62%
// Memory Usage: 24.7 MB, less than 98.42%