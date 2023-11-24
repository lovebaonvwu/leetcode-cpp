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
class BSTIterator {
  vector<int> vals;
  int cur = -1;

  void dfs(TreeNode* root, vector<int>& vals) {
    if (!root) {
      return;
    }

    dfs(root->left, vals);
    vals.push_back(root->val);
    dfs(root->right, vals);
  }

 public:
  BSTIterator(TreeNode* root) { dfs(root, vals); }

  bool hasNext() { return cur < (int)vals.size() - 1; }

  int next() { return vals[++cur]; }

  bool hasPrev() { return cur > 0; }

  int prev() { return vals[--cur]; }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * bool param_1 = obj->hasNext();
 * int param_2 = obj->next();
 * bool param_3 = obj->hasPrev();
 * int param_4 = obj->prev();
 */
// Runtime 378 ms
// Memory 150.9 MB
// 2023.1.30 at 奥盛大厦