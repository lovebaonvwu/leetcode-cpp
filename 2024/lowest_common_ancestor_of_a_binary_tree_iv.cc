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
  TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*>& nodes) {
    unordered_set<int> st;
    for (auto node : nodes) {
      st.insert(node->val);
    }

    int n = nodes.size();
    function<TreeNode*(TreeNode*, int&)> dfs = [&](TreeNode* root,
                                                   int& cnt) -> TreeNode* {
      if (!root) {
        return nullptr;
      }

      int leftCnt = 0;
      TreeNode* left = dfs(root->left, leftCnt);
      cnt += leftCnt;
      if (leftCnt == n) {
        return left;
      }
      int rightCnt = 0;
      TreeNode* right = dfs(root->right, rightCnt);
      cnt += rightCnt;
      if (rightCnt == n) {
        return right;
      }

      if (st.find(root->val) != st.end()) {
        ++cnt;
      }

      if (cnt == n) {
        return root;
      }

      return nullptr;
    };

    int cnt = 0;
    return dfs(root, cnt);
  }
};
// 96 ms
// 45.12 MB
