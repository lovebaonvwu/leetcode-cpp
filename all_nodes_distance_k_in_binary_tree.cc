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
  unordered_map<TreeNode*, TreeNode*> graph;
  unordered_set<TreeNode*> visited;
  queue<TreeNode*> q;

 public:
  vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    vector<int> ans;

    dfs(root, target);

    while (!q.empty() && K >= 0) {
      int cnt = q.size();

      while (cnt-- > 0) {
        auto node = q.front();
        q.pop();

        if (K == 0) {
          ans.push_back(node->val);
        }

        visited.insert(node);

        if (node->left && !visited.count(node->left)) {
          q.push(node->left);
        }

        if (node->right && !visited.count(node->right)) {
          q.push(node->right);
        }

        if (graph[node] && !visited.count(graph[node])) {
          q.push(graph[node]);
        }
      }

      --K;
    }

    return ans;
  }

  void dfs(TreeNode* root, TreeNode* target) {
    if (!root) {
      return;
    }

    if (root == target) {
      q.push(root);
      return;
    }

    if (root->left) {
      graph[root->left] = root;
      dfs(root->left, target);
    }

    if (root->right) {
      graph[root->right] = root;
      dfs(root->right, target);
    }
  }
};
// Runtime: 8 ms, faster than 61.90%
// Memory Usage: 15 MB, less than 39.98%