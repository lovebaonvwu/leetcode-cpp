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
  vector<int> ans;
  int cnt = 0;
  int max_cnt = 0;
  int* prev_val = nullptr;

 public:
  vector<int> findMode(TreeNode* root) {
    inorder(root);

    return ans;
  }

  void inorder(TreeNode* root) {
    if (!root) {
      return;
    }

    inorder(root->left);

    if (prev_val && *prev_val == root->val) {
      ++cnt;
    } else {
      cnt = 1;
    }

    if (cnt > max_cnt) {
      max_cnt = cnt;

      ans.clear();
      ans.push_back(root->val);
    } else if (cnt == max_cnt) {
      ans.push_back(root->val);
    }

    prev_val = &root->val;

    inorder(root->right);
  }
};
// Runtime: 24 ms, faster than 71.90%
// Memory Usage: 22.2 MB, less than 100.00%

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
  vector<int> ans;
  int cnt = 0;
  unordered_map<int, int> mp;

 public:
  vector<int> findMode(TreeNode* root) {
    inorder(root);

    return ans;
  }

  void inorder(TreeNode* root) {
    if (!root) {
      return;
    }

    inorder(root->left);

    ++mp[root->val];

    if (mp[root->val] > cnt) {
      cnt = mp[root->val];

      ans.clear();
      ans.push_back(root->val);
    } else if (mp[root->val] == cnt) {
      ans.push_back(root->val);
    }

    inorder(root->right);
  }
};
// Runtime: 32 ms, faster than 34.86%
// Memory Usage: 26.6 MB, less than 42.86%