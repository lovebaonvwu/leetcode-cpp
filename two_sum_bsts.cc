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
  bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
    if (!root1 || !root2) {
      return false;
    }

    if (root1->val + root2->val == target) {
      return true;
    }

    if (root1->val + root2->val > target) {
      return twoSumBSTs(root1->left, root2, target) ||
             twoSumBSTs(root1, root2->left, target);
    }

    if (root1->val + root2->val < target) {
      return twoSumBSTs(root1->right, root2, target) ||
             twoSumBSTs(root1, root2->right, target);
    }

    return false;
  }
};
// Runtime 2355 ms
// Memory 28.4 MB
// 2023.1.30 at 奥盛大厦

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
  bool search(TreeNode* root, int target) {
    if (!root) {
      return false;
    }

    if (root->val == target) {
      return true;
    }

    if (root->val > target) {
      return search(root->left, target);
    } else {
      return search(root->right, target);
    }
  }

 public:
  bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
    if (!root1) {
      return false;
    }

    if (search(root2, target - root1->val)) {
      return true;
    }

    return twoSumBSTs(root1->left, root2, target) ||
           twoSumBSTs(root1->right, root2, target);
  }
};
// Runtime 32 ms
// Memory 28.5 MB
// 2023.1.30 at 奥盛大厦