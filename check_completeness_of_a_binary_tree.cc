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
  bool isCompleteTree(TreeNode* root) {
    vector<TreeNode*> vect;

    vect.push_back(root);

    int i = 0;

    while (i < vect.size() && vect[i]) {
      vect.push_back(vect[i]->left);
      vect.push_back(vect[i]->right);

      ++i;
    }

    while (i < vect.size() && !vect[i]) {
      ++i;
    }

    return i == vect.size();
  }
};  // 4ms

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
  bool isCompleteTree(TreeNode* root) {
    int cnt = 0;

    count(root, cnt);

    return dfs(root, 1, cnt);
  }

  void count(TreeNode* root, int& cnt) {
    if (!root) {
      return;
    }

    ++cnt;
    count(root->left, cnt);
    count(root->right, cnt);
  }

  bool dfs(TreeNode* root, int idx, int cnt) {
    if (!root) {
      return true;
    }

    if (idx > cnt) {
      return false;
    }

    return dfs(root->left, 2 * idx, cnt) && dfs(root->right, 2 * idx + 1, cnt);
  }
};  // 8msg