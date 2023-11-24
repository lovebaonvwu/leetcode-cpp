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
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return buildTree(nums, 0, nums.size() - 1);
  }

  TreeNode* buildTree(vector<int>& nums, int start, int end) {
    if (start > end) {
      return nullptr;
    } else if (start == end) {
      return new TreeNode(nums[start]);
    } else {
      int mid = (start + end) >> 1;
      TreeNode* node = new TreeNode(nums[mid]);

      node->left = buildTree(nums, start, mid - 1);
      node->right = buildTree(nums, mid + 1, end);

      return node;
    }
  }
};  // 20ms

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
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return buildTree(nums, 0, nums.size() - 1);
  }

  TreeNode* buildTree(vector<int>& nums, int start, int end) {
    if (start > end)
      return nullptr;

    if (start == end) {
      return new TreeNode(nums[start]);
    }

    int mid = (start + end) >> 1;
    TreeNode* node = new TreeNode(nums[mid]);

    node->left = buildTree(nums, start, mid - 1);
    node->right = buildTree(nums, mid + 1, end);

    return node;
  }
};  // 28ms