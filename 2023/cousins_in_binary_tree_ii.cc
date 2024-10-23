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
  unordered_map<int, int> mp;

 public:
  TreeNode* replaceValueInTree(TreeNode* root) {
    bfs(root);
    dfs(root, 0);

    return root;
  }

 private:
  void bfs(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int lvl = 0;
    while (!q.empty()) {
      int cnt = q.size();
      int sum = 0;
      while (cnt-- > 0) {
        auto node = q.front();
        q.pop();

        sum += node->val;
        if (node->left) {
          q.push(node->left);
        }

        if (node->right) {
          q.push(node->right);
        }
      }

      mp[lvl++] = sum;
    }
  }

  void dfs(TreeNode* root, int lvl) {
    if (!root) {
      return;
    }

    dfs(root->left, lvl + 1);
    dfs(root->right, lvl + 1);

    int sum = root->left ? root->left->val : 0;
    sum += root->right ? root->right->val : 0;

    if (root->left) {
      root->left->val = mp[lvl + 1] - sum;
    }

    if (root->right) {
      root->right->val = mp[lvl + 1] - sum;
    }

    if (lvl == 0) {
      root->val = 0;
    }
  }
};
// Runtime 695 ms
// Memory 294.9 MB

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
public:
    TreeNode* replaceValueInTree(TreeNode* root) 
    {
        vector<int> levelSums;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) 
        {
            int cnt = q.size();
            int sum = 0;
            while (cnt-- > 0)
            {
                auto node = q.front();
                q.pop();

                sum += node->val;
                if (node->left)
                {
                    q.push(node->left);
                }

                if (node->right)
                {
                    q.push(node->right);
                }
            }

            levelSums.push_back(sum);
        }

        q.push(root);
        root->val = 0;
        int levelIndex = 1;
        while (!q.empty()) {
            int cnt = q.size();
            while (cnt-- > 0) {
                auto node = q.front();
                q.pop();

                int sum = 0;
                if (node->left) {
                    sum += node->left->val;
                }

                if (node->right) {
                    sum += node->right->val;
                }

                if (node->left) {
                    node->left->val = levelSums[levelIndex] - sum;
                    q.push(node->left);
                }

                if (node->right) {
                    node->right->val = levelSums[levelIndex] - sum;
                    q.push(node->right);
                }
            }

            ++levelIndex;
        }

        return root;
    }
private:
};
// 10 ms
// 323.95 MB