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
  int minimumOperations(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);

    int ans = 0;
    while (!q.empty()) {
      int cnt = q.size();
      vector<int> vals;

      while (cnt-- > 0) {
        auto node = q.front();
        q.pop();

        if (node->left) {
          q.push(node->left);
          vals.push_back(node->left->val);
        }

        if (node->right) {
          q.push(node->right);
          vals.push_back(node->right->val);
        }
      }

      vector<int> ids(vals.size());
      iota(ids.begin(), ids.end(), 0);
      sort(ids.begin(), ids.end(),
           [&](int a, int b) { return vals[a] < vals[b]; });

      for (int i = 0; i < ids.size(); ++i) {
        for (; ids[i] != i;) {
          swap(ids[i], ids[ids[i]]);
          ++ans;
        }
      }
    }

    return ans;
  }
};
// Runtime 534 ms
// Memory 125.8 MB
// 2022.11.14 at 奥盛大厦