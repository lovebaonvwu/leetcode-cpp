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
  unordered_set<int> st;
  vector<TreeNode*> ans;

 public:
  vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    for (auto n : to_delete) {
      st.insert(n);
    }

    if (!dfs(root)) {
      ans.push_back(root);
    }

    return ans;
  }

  bool dfs(TreeNode* root) {
    if (!root) {
      return false;
    }

    if (dfs(root->left)) {
      root->left = nullptr;
    }

    if (dfs(root->right)) {
      root->right = nullptr;
    }

    if (st.count(root->val)) {
      if (root->left) {
        ans.push_back(root->left);
      }

      if (root->right) {
        ans.push_back(root->right);
      }

      return true;
    }

    return false;
  }
};
// Runtime: 68 ms, faster than 8.91%
// Memory Usage: 37.8 MB, less than 100.00%

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
  unordered_set<int> st;
  vector<TreeNode*> ans;

 public:
  vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    for (auto n : to_delete) {
      st.insert(n);
    }

    dfs(root);

    if (root) {
      ans.push_back(root);
    }

    return ans;
  }

  void dfs(TreeNode*& node) {
    if (!node) {
      return;
    }

    dfs(node->left);
    dfs(node->right);

    if (st.find(node->val) != st.end()) {
      if (node->left) {
        ans.push_back(node->left);
      }

      if (node->right) {
        ans.push_back(node->right);
      }

      node = nullptr;
    }
  }
};
// Runtime: 80 ms, faster than 8.16%
// Memory Usage: 37.8 MB, less than 100.00%

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
  unordered_set<int> st;
  vector<TreeNode*> ans;

 public:
  vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    for (auto n : to_delete) {
      st.insert(n);
    }

    dfs(root, true);

    return ans;
  }

  TreeNode* dfs(TreeNode* node, bool is_root) {
    if (!node) {
      return nullptr;
    }

    int deleted = st.find(node->val) != st.end();

    if (is_root && !deleted) {
      ans.push_back(node);
    }

    node->left = dfs(node->left, deleted);
    node->right = dfs(node->right, deleted);

    return deleted ? nullptr : node;
  }
};
// Runtime: 80 ms, faster than 8.16%
// Memory Usage: 37.7 MB, less than 100.00%

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
  unordered_set<int> st;
  vector<TreeNode*> ans;

 public:
  vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    if (!root) {
      return ans;
    }

    for (auto n : to_delete) {
      st.insert(n);
    }

    ans.push_back(root);

    for (int i = 0; i < ans.size();) {
      if (st.count(ans[i]->val)) {
        if (ans[i]->left) {
          ans.push_back(ans[i]->left);
        }

        if (ans[i]->right) {
          ans.push_back(ans[i]->right);
        }

        ans.erase(ans.begin() + i);
      } else {
        dfs(ans[i]);
        ++i;
      }
    }

    return ans;
  }

  void dfs(TreeNode* root) {
    if (!root) {
      return;
    }

    if (root->left && st.count(root->left->val)) {
      if (root->left->left) {
        ans.push_back(root->left->left);
      }

      if (root->left->right) {
        ans.push_back(root->left->right);
      }

      root->left = nullptr;
    }

    if (root->right && st.count(root->right->val)) {
      if (root->right->left) {
        ans.push_back(root->right->left);
      }

      if (root->right->right) {
        ans.push_back(root->right->right);
      }

      root->right = nullptr;
    }

    dfs(root->left);
    dfs(root->right);
  }
};
// Runtime: 80 ms, faster than 8.16%
// Memory Usage: 37.8 MB, less than 100.00%

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
  unordered_set<int> st;
  vector<TreeNode*> ans;

 public:
  vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    if (!root) {
      return ans;
    }

    for (auto n : to_delete) {
      st.insert(n);
    }

    ans.push_back(root);

    for (int i = 0; i < ans.size();) {
      if (st.count(ans[i]->val)) {
        st.erase(ans[i]->val);

        if (ans[i]->left) {
          ans.push_back(ans[i]->left);
        }

        if (ans[i]->right) {
          ans.push_back(ans[i]->right);
        }

        ans.erase(ans.begin() + i);
      } else {
        dfs(ans[i]);
        ++i;
      }
    }

    return ans;
  }

  void dfs(TreeNode* root) {
    if (!root) {
      return;
    }

    if (root->left && st.count(root->left->val)) {
      if (root->left->left) {
        ans.push_back(root->left->left);
      }

      if (root->left->right) {
        ans.push_back(root->left->right);
      }

      root->left = nullptr;
    }

    if (root->right && st.count(root->right->val)) {
      if (root->right->left) {
        ans.push_back(root->right->left);
      }

      if (root->right->right) {
        ans.push_back(root->right->right);
      }

      root->right = nullptr;
    }

    dfs(root->left);
    dfs(root->right);
  }
};
// Runtime: 88 ms, faster than 7.35%
// Memory Usage: 37.8 MB, less than 100.00%

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
  unordered_set<int> st;
  vector<TreeNode*> ans;

 public:
  vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    if (!root) {
      return {};
    }

    for (auto n : to_delete) {
      st.insert(n);
    }

    ans.push_back(root);

    for (int i = 0; i < ans.size(); ++i) {
      if (st.count(ans[i]->val)) {
        if (ans[i]->left) {
          ans.push_back(ans[i]->left);
        }

        if (ans[i]->right) {
          ans.push_back(ans[i]->right);
        }

        st.erase(ans[i]->val);
        ans[i] = nullptr;
      } else {
        dfs(ans[i], nullptr, true);
      }
    }

    vector<TreeNode*> ret;

    for (int i = 0; i < ans.size(); ++i) {
      if (ans[i]) {
        ret.push_back(ans[i]);
      }
    }

    return ret;
  }

  void dfs(TreeNode* root, TreeNode* parent, bool left) {
    if (!root) {
      return;
    }

    if (st.count(root->val)) {
      if (parent && left) {
        parent->left = nullptr;
      } else if (parent && !left) {
        parent->right = nullptr;
      }

      if (root->left) {
        ans.push_back(root->left);
      }

      if (root->right) {
        ans.push_back(root->right);
      }

      st.erase(root->val);
    } else {
      dfs(root->left, root, true);
      dfs(root->right, root, false);
    }
  }
};
// Runtime: 88 ms, faster than 7.35%
// Memory Usage: 37.9 MB, less than 100.00%