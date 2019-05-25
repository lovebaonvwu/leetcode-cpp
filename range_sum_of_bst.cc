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
  int rangeSumBST(TreeNode* root, int L, int R) {
    int sum = 0;

    dfs(root, L, R, sum);

    return sum;
  }

  void dfs(TreeNode* root, int& L, int& R, int& sum) {
    if (!root) {
      return;
    }

    if (root->val < L) {
      dfs(root->right, L, R, sum);
      return;
    }

    if (root->val > R) {
      dfs(root->left, L, R, sum);
      return;
    }

    dfs(root->left, L, R, sum);
    sum += root->val;
    dfs(root->right, L, R, sum);
  }
};  // 136ms

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
  int rangeSumBST(TreeNode* root, int L, int R) {
    if (!root) {
      return 0;
    }

    int sum = 0;

    if (root) {
      if (root->val >= L && root->val <= R) {
        sum += root->val;
      }

      if (root->val > L) {
        sum += rangeSumBST(root->left, L, R);
      }

      if (root->val < R) {
        sum += rangeSumBST(root->right, L, R);
      }
    }

    return sum;
  }
};  // 136ms

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
  int rangeSumBST(TreeNode* root, int L, int R) {
    int sum = 0;

    dfs(root, L, R, sum);

    return sum;
  }

  void dfs(TreeNode* root, int& L, int& R, int& sum) {
    if (!root) {
      return;
    }

    if (root->val < L) {
      dfs(root->right, L, R, sum);
      return;
    }

    if (root->val > R) {
      dfs(root->left, L, R, sum);
      return;
    }

    if (root->left) {
      dfs(root->left, L, R, sum);
    }

    sum += root->val;

    if (root->right) {
      dfs(root->right, L, R, sum);
    }
  }
};  // 156ms