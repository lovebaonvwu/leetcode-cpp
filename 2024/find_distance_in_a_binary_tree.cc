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
  TreeNode* findLCA(TreeNode* root, int p, int q) {
    if (!root || root->val == p || root->val == q) {
      return root;
    }

    TreeNode* left = findLCA(root->left, p, q);
    TreeNode* right = findLCA(root->right, p, q);

    if (left && right) {
      return root;
    }

    return left ? left : (right ? right : nullptr);
  }

  int depth(TreeNode* root, int target) {
    if (!root) {
      return -1;
    }
    if (root->val == target) {
      return 0;
    }

    int d = max(depth(root->left, target), depth(root->right, target));

    return d == -1 ? d : d + 1;
  }

 public:
  int findDistance(TreeNode* root, int p, int q) {
    TreeNode* lca = findLCA(root, p, q);

    return depth(lca, p) + depth(lca, q);
  }
};
// 31 ms
// 30.12 MB
