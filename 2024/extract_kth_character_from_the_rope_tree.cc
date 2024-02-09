/**
 * Definition for a rope tree node.
 * struct RopeTreeNode {
 *     int len;
 *     string val;
 *     RopeTreeNode *left;
 *     RopeTreeNode *right;
 *     RopeTreeNode() : len(0), val(""), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(string s) : len(0), val(std::move(s)), left(nullptr),
 * right(nullptr) {} RopeTreeNode(int x) : len(x), val(""), left(nullptr),
 * right(nullptr) {} RopeTreeNode(int x, RopeTreeNode *left, RopeTreeNode
 * *right) : len(x), val(""), left(left), right(right) {}
 * };
 */
class Solution {
 public:
  char getKthCharacter(RopeTreeNode* root, int k) {
    function<string(RopeTreeNode*)> dfs = [&](RopeTreeNode* root) -> string {
      if (!root)
        return "";
      if (!root->left && !root->right)
        return root->val;

      return dfs(root->left) + dfs(root->right);
    };

    return dfs(root)[k - 1];
  }
};
// 39 ms
// 39.62 MB