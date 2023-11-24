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
  int kthSmallest(TreeNode* root, int k) {
    int ans = -1;

    dfs(root, k, ans);

    return ans;
  }

  void dfs(TreeNode* root, int& k, int& ans) {
    if (!root) {
      return;
    }

    dfs(root->left, k, ans);

    if (--k == 0) {
      ans = root->val;
      return;
    }

    dfs(root->right, k, ans);
  }
};  // 20ms

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
  int kthSmallest(TreeNode* root, int k) {
    vector<int> arr;

    dfs(root, arr);

    return arr[k - 1];
  }

  void dfs(TreeNode* root, vector<int>& arr) {
    if (!root) {
      return;
    }

    dfs(root->left, arr);
    arr.push_back(root->val);
    dfs(root->right, arr);
  }
};  // 20ms

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
  int kthSmallest(TreeNode* root, int k) {
    priority_queue<int> heap;
    int ans = -1;

    dfs(root, heap);

    k = heap.size() - k;
    for (int i = 0; i < k; ++i) {
      heap.pop();
    }

    return heap.top();
  }

  void dfs(TreeNode* root, priority_queue<int>& heap) {
    if (!root) {
      return;
    }

    dfs(root->left, heap);
    heap.push(root->val);
    dfs(root->right, heap);
  }
};  // 36ms