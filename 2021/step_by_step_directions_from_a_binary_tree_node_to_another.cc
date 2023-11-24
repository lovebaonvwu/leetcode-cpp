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
  TreeNode* LCA(TreeNode* root, int a, int b) {
    if (!root) {
      return nullptr;
    }

    if (root->val == a || root->val == b) {
      return root;
    }

    auto l = LCA(root->left, a, b);
    auto r = LCA(root->right, a, b);

    if (l && r) {
      return root;
    } else if (l) {
      return l;
    } else {
      return r;
    }
  }

  bool buildPath(TreeNode* root, string& s, int target) {
    if (!root) {
      return false;
    }

    if (root->val == target) {
      return true;
    }

    s += 'L';
    if (buildPath(root->left, s, target)) {
      return true;
    } else {
      s.pop_back();
    }

    s += 'R';
    if (buildPath(root->right, s, target)) {
      return true;
    } else {
      s.pop_back();
    }

    return false;
  }

 public:
  string getDirections(TreeNode* root, int startValue, int destValue) {
    root = LCA(root, startValue, destValue);
    string startPath, destPath;

    buildPath(root, startPath, startValue);
    buildPath(root, destPath, destValue);

    for (auto& c : startPath) {
      c = 'U';
    }

    return startPath + destPath;
  }
};
// Runtime: 204 ms, faster than 76.23%
// Memory Usage: 115.3 MB, less than 61.13%
// 2021.12.7 at 奥盛大厦

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
  bool buildPath(TreeNode* root, string& s, int target) {
    if (!root) {
      return false;
    }

    if (root->val == target) {
      return true;
    }

    if (buildPath(root->left, s, target)) {
      s += 'L';
      return true;
    }

    if (buildPath(root->right, s, target)) {
      s += 'R';
      return true;
    }

    return false;
  }

 public:
  string getDirections(TreeNode* root, int startValue, int destValue) {
    string startPath, destPath;

    buildPath(root, startPath, startValue);
    buildPath(root, destPath, destValue);

    while (!startPath.empty() && !destPath.empty() &&
           startPath.back() == destPath.back()) {
      startPath.pop_back();
      destPath.pop_back();
    }

    for (auto& c : startPath) {
      c = 'U';
    }

    return startPath + string(destPath.rbegin(), destPath.rend());
  }
};
// Runtime: 168 ms, faster than 99.00%
// Memory Usage: 113.8 MB, less than 85.07%
// 2021.12.7 at 奥盛大厦