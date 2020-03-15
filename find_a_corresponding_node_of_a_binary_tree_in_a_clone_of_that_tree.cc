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
  TreeNode* getTargetCopy(TreeNode* original,
                          TreeNode* cloned,
                          TreeNode* target) {
    if (!cloned) {
      return nullptr;
    }

    if (cloned->val == target->val) {
      return cloned;
    }

    TreeNode* left = getTargetCopy(original->left, cloned->left, target);
    if (left) {
      return left;
    }

    return getTargetCopy(original->right, cloned->right, target);
  }
};
// Runtime: 544 ms, faster than 18.15%
// Memory Usage: 167.4 MB, less than 100.00%

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
  TreeNode* getTargetCopy(TreeNode* original,
                          TreeNode* cloned,
                          TreeNode* target) {
    return !original ? nullptr
                     : original == target
                           ? cloned
                           : getTargetCopy(original->left, cloned->left, target)
                                 ?: getTargetCopy(original->right,
                                                  cloned->right, target);
  }
};
// Runtime: 548 ms, faster than 11.64%
// Memory Usage: 167.5 MB, less than 100.00%