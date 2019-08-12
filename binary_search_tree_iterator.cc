/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
  priority_queue<int, vector<int>, greater<>> pq;

 public:
  BSTIterator(TreeNode* root) {
    stack<TreeNode*> stk;

    if (!root) {
      return;
    }

    stk.push(root);

    while (!stk.empty()) {
      TreeNode* node = stk.top();

      if (node->left) {
        stk.push(node->left);
        node->left = nullptr;
      } else {
        pq.push(node->val);
        stk.pop();

        if (node->right) {
          stk.push(node->right);
        }
      }
    }
  }

  /** @return the next smallest number */
  int next() {
    int res = pq.top();

    pq.pop();

    return res;
  }

  /** @return whether we have a next smallest number */
  bool hasNext() { return !pq.empty(); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// 48ms