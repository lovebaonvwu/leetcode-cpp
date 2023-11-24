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
  TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    unordered_map<int, TreeNode*> mp;
    unordered_map<int, bool> isChild;

    for (auto& d : descriptions) {
      if (mp.find(d[0]) == mp.end()) {
        mp[d[0]] = new TreeNode(d[0]);
      }

      TreeNode* p = mp[d[0]];

      if (mp.find(d[1]) == mp.end()) {
        mp[d[1]] = new TreeNode(d[1]);
      }

      TreeNode* child = mp[d[1]];

      if (d[2] == 1) {
        p->left = child;
      } else {
        p->right = child;
      }

      isChild[d[1]] = true;
    }

    TreeNode* head;
    for (auto& d : descriptions) {
      if (!isChild[d[0]]) {
        head = mp[d[0]];
        break;
      }
    }

    return head;
  }
};
// Runtime: 1364 ms, faster than 7.69%
// Memory Usage: 277.8 MB, less than 7.69%
// 2022.3.7 at 奥盛大厦