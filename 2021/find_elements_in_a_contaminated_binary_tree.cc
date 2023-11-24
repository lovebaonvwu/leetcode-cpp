/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
  unordered_set<int> st;

 public:
  FindElements(TreeNode* root) {
    queue<TreeNode*> q;

    root->val = 0;

    q.push(root);
    st.insert(root->val);

    while (!q.empty()) {
      int sz = q.size();

      while (sz-- > 0) {
        TreeNode* node = q.front();
        q.pop();

        if (node->left) {
          node->left->val = node->val * 2 + 1;
          st.insert(node->left->val);
          q.push(node->left);
        }

        if (node->right) {
          node->right->val = node->val * 2 + 2;
          st.insert(node->right->val);
          q.push(node->right);
        }
      }
    }
  }

  bool find(int target) { return st.count(target); }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
// Runtime: 32 ms, faster than 96.11%
// Memory Usage: 19.5 MB, less than 100.00%

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
  TreeNode* r;
  unordered_set<int> st;

 public:
  FindElements(TreeNode* root) {
    queue<TreeNode*> q;

    root->val = 0;

    q.push(root);
    st.insert(root->val);

    while (!q.empty()) {
      int sz = q.size();

      while (sz-- > 0) {
        TreeNode* node = q.front();
        q.pop();

        if (node->left) {
          node->left->val = node->val * 2 + 1;
          st.insert(node->left->val);
          q.push(node->left);
        }

        if (node->right) {
          node->right->val = node->val * 2 + 2;
          st.insert(node->right->val);
          q.push(node->right);
        }
      }
    }

    r = root;
  }

  bool find(int target) { return st.count(target); }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
// Runtime: 40 ms, faster than 78.42%
// Memory Usage: 19.3 MB, less than 100.00%

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
  unordered_set<int> st;

 public:
  FindElements(TreeNode* root) { dfs(root, 0); }

  void dfs(TreeNode* root, int val) {
    if (!root) {
      return;
    }

    root->val = val;
    st.insert(val);

    dfs(root->left, val * 2 + 1);
    dfs(root->right, val * 2 + 2);
  }

  bool find(int target) { return st.count(target); }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
// Runtime: 44 ms, faster than 60.67%
// Memory Usage: 29.9 MB, less than 100.00%

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
  TreeNode* r;

 public:
  FindElements(TreeNode* root) {
    queue<TreeNode*> q;

    root->val = 0;

    q.push(root);

    while (!q.empty()) {
      int sz = q.size();

      while (sz-- > 0) {
        TreeNode* node = q.front();
        q.pop();

        if (node->left) {
          node->left->val = node->val * 2 + 1;
          q.push(node->left);
        }

        if (node->right) {
          node->right->val = node->val * 2 + 2;
          q.push(node->right);
        }
      }
    }

    r = root;
  }

  bool find(int target) { return dfs(r, target); }

  bool dfs(TreeNode* root, int& target) {
    if (!root) {
      return false;
    }

    if (root->val == target) {
      return true;
    }

    return dfs(root->left, target) || dfs(root->right, target);
  }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
// Runtime: 948 ms, faster than 5.34%
// Memory Usage: 17.8 MB, less than 100.00%