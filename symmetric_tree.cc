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
  bool isSymmetric(TreeNode* root) { return isMirror(root, root); }

  bool isMirror(TreeNode* left, TreeNode* right) {
    if (!left && !right)
      return true;

    if (!left || !right)
      return false;

    return (left->val == right->val) && isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
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
  bool isSymmetric(TreeNode* root) {
    vector<int> left;
    vector<int> right;

    dfsLeft(root, left);
    dfsRight(root, right);

    return left == right;
  }

  void dfsLeft(TreeNode* root, vector<int>& vec) {
    if (!root) {
      vec.push_back(-1);
      return;
    }

    vec.push_back(root->val);
    dfsLeft(root->left, vec);
    dfsLeft(root->right, vec);
  }

  void dfsRight(TreeNode* root, vector<int>& vec) {
    if (!root) {
      vec.push_back(-1);
      return;
    }

    vec.push_back(root->val);
    dfsRight(root->right, vec);
    dfsRight(root->left, vec);
  }
};  // 8ms