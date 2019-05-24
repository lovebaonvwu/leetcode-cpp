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
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> in_map;

    for (int i = 0; i < inorder.size(); ++i) {
      in_map[inorder[i]] = i;
    }

    return build(inorder, postorder, 0, inorder.size() - 1, 0,
                 postorder.size() - 1, in_map);
  }

  TreeNode* build(vector<int>& inorder,
                  vector<int>& postorder,
                  int in_start,
                  int in_end,
                  int post_start,
                  int post_end,
                  unordered_map<int, int>& in_map) {
    if (post_start > post_end) {
      return nullptr;
    }

    TreeNode* node = new TreeNode(postorder[post_end]);

    int index = in_map[node->val];

    int left_size = index - in_start;
    int right_size = in_end - index;

    node->left = build(inorder, postorder, in_start, in_start + left_size - 1,
                       post_start, post_start + left_size - 1, in_map);
    node->right =
        build(inorder, postorder, index + 1, in_end, post_start + left_size,
              post_start + left_size + right_size - 1, in_map);
    return node;
  }
};  // 16ms