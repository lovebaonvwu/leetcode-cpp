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
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    int cnt = 0;

    return buildTree(preorder, cnt, INT_MAX);
  }

  TreeNode* buildTree(vector<int>& preorder, int& cnt, int rootVal) {
    if (cnt >= preorder.size() || preorder[cnt] > rootVal) {
      return nullptr;
    }

    TreeNode* node = new TreeNode(preorder[cnt++]);

    node->left = buildTree(preorder, cnt, node->val);
    node->right = buildTree(preorder, cnt, rootVal);

    return node;
  }
};  // 0ms

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
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    return buildTree(preorder, 0, preorder.size() - 1);
  }

  TreeNode* buildTree(vector<int>& preorder, int begin, int end) {
    if (begin > end) {
      return nullptr;
    }

    if (begin == end) {
      return new TreeNode(preorder[begin]);
    }

    TreeNode* head = new TreeNode(preorder[begin]);

    int pos = end + 1;
    for (int i = begin + 1; i <= end; ++i) {
      if (preorder[i] > preorder[begin]) {
        pos = i;
        break;
      }
    }

    head->left = buildTree(preorder, begin + 1, pos - 1);
    head->right = buildTree(preorder, pos, end);

    return head;
  }
};  // 8ms

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
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    if (!preorder.size()) {
      return nullptr;
    }

    TreeNode* root = new TreeNode(preorder[0]);

    for (int i = 1; i < preorder.size(); ++i) {
      preorderInsert(root, preorder[i]);
    }

    return root;
  }

  TreeNode* preorderInsert(TreeNode* root, int val) {
    if (!root) {
      return new TreeNode(val);
    }

    if (val < root->val) {
      root->left = preorderInsert(root->left, val);
    } else if (val > root->val) {
      root->right = preorderInsert(root->right, val);
    }

    return root;
  }
};  // 8ms