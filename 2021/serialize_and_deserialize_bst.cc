/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string s;

    preorder(root, s);

    return s;
  }

  void preorder(TreeNode* root, string& s) {
    if (!root) {
      return;
    }

    s += to_string(root->val);
    s += "\n";

    preorder(root->left, s);
    preorder(root->right, s);
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    vector<int> vals;

    stringstream ss(data);

    string val;
    while (ss >> val) {
      vals.push_back(stoi(val));
    }

    return dfs(vals, 0, vals.size());
  }

  TreeNode* dfs(vector<int>& vals, int start, int end) {
    if (start + 1 > end) {
      return nullptr;
    }

    if (start + 1 == end) {
      return new TreeNode(vals[start]);
    }

    TreeNode* node = new TreeNode(vals[start]);

    int i = start + 1;
    while (i < end && vals[i] < vals[start]) {
      ++i;
    }

    node->left = dfs(vals, start + 1, i);
    node->right = dfs(vals, i, end);

    return node;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// Runtime: 40 ms, faster than 84.94%
// Memory Usage: 28 MB, less than 5.45%

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string s;

    preorder(root, s);

    return s;
  }

  void preorder(TreeNode* root, string& s) {
    if (!root) {
      return;
    }

    s += to_string(root->val);
    s += "\n";

    preorder(root->left, s);
    preorder(root->right, s);
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    vector<int> vals;

    stringstream ss(data);

    string val;
    while (ss >> val) {
      vals.push_back(stoi(val));
    }

    int cur = 0;
    return dfs(vals, cur, INT_MIN, INT_MAX);
  }

  TreeNode* dfs(vector<int>& vals, int& cur, int min, int max) {
    if (cur >= vals.size() || vals[cur] < min || vals[cur] > max) {
      return nullptr;
    }

    int val = vals[cur++];
    TreeNode* node = new TreeNode(val);

    node->left = dfs(vals, cur, min, val);
    node->right = dfs(vals, cur, val, max);

    return node;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// Runtime: 40 ms, faster than 84.94%
// Memory Usage: 27.9 MB, less than 5.45%