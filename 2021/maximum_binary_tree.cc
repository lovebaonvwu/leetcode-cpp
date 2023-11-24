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
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    vector<TreeNode*> stk;

    for (int i = 0; i < nums.size(); ++i) {
      TreeNode* node = new TreeNode(nums[i]);

      while (!stk.empty() && stk.back()->val < node->val) {
        node->left = stk.back();
        stk.pop_back();
      }

      if (!stk.empty()) {
        stk.back()->right = node;
      }

      stk.push_back(node);
    }

    return stk.front();
  }
};
// Runtime: 92 ms, faster than 84.24%
// Memory Usage: 34.3 MB, less than 19.44%

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
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return constructMBT(nums, 0, nums.size());
  }

  TreeNode* constructMBT(vector<int>& nums, int begin, int end) {
    if (begin >= end) {
      return nullptr;
    }

    auto it = max_element(nums.begin() + begin, nums.begin() + end);
    int pos = it - nums.begin();

    TreeNode* root = new TreeNode(*it);

    root->left = constructMBT(nums, begin, pos);
    root->right = constructMBT(nums, pos + 1, end);

    return root;
  }
};
// Runtime: 96 ms, faster than 75.52%
// Memory Usage: 36.6 MB, less than 16.67%