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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int index = 0;
    unordered_map<int, int> in_map;

    for (int i = 0; i < inorder.size(); ++i) {
      in_map[inorder[i]] = i;
    }

    return build(preorder, index, inorder, 0, inorder.size() - 1, in_map);
  }

  TreeNode* build(vector<int>& preorder,
                  int& index,
                  vector<int>& inorder,
                  int begin,
                  int end,
                  unordered_map<int, int>& in_map) {
    if (index == preorder.size() || begin > end) {
      return nullptr;
    }

    TreeNode* node = new TreeNode(preorder[index++]);

    if (begin == end) {
      return node;
    }

    int pos = in_map[node->val];

    node->left = build(preorder, index, inorder, begin, pos - 1, in_map);
    node->right = build(preorder, index, inorder, pos + 1, end, in_map);

    return node;
  }
};  // 12ms

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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int index = 0;
    unordered_map<int, int> in_map;

    for (int i = 0; i < inorder.size(); ++i) {
      in_map[inorder[i]] = i;
    }

    return build(preorder, index, 0, inorder.size() - 1, in_map);
  }

  TreeNode* build(vector<int>& preorder,
                  int& index,
                  int begin,
                  int end,
                  unordered_map<int, int>& in_map) {
    if (index == preorder.size() || begin > end) {
      return nullptr;
    }

    TreeNode* node = new TreeNode(preorder[index++]);

    if (begin == end) {
      return node;
    }

    int pos = in_map[node->val];

    node->left = build(preorder, index, begin, pos - 1, in_map);
    node->right = build(preorder, index, pos + 1, end, in_map);

    return node;
  }
};  // 16ms

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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int index = 0;
    return build(preorder, index, inorder, 0, inorder.size() - 1);
  }

  TreeNode* build(vector<int>& preorder,
                  int& index,
                  vector<int>& inorder,
                  int begin,
                  int end) {
    if (index == preorder.size() || begin > end) {
      return nullptr;
    }

    TreeNode* node = new TreeNode(preorder[index++]);

    if (begin == end) {
      return node;
    }

    int pos = 0;

    for (int i = 0; i < inorder.size(); ++i) {
      if (inorder[i] == node->val) {
        break;
      }
      ++pos;
    }

    node->left = build(preorder, index, inorder, begin, pos - 1);
    node->right = build(preorder, index, inorder, pos + 1, end);

    return node;
  }
};  // 24ms