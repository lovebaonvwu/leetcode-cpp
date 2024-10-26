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
class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<int, int> height;

        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            if (!node) {
                return -1;
            }

            height[node->val] = max(dfs(node->left), dfs(node->right)) + 1;

            return height[node->val];
        };

        dfs(root);

        unordered_map<int, int> depth;
        function<void(TreeNode*, int, int)> dfs2 = [&](TreeNode* node, int cur_depth, int max_depth) -> void {
            if (!node) {
                return;
            }

            depth[node->val] = max_depth;

            dfs2(node->left, cur_depth + 1, max(max_depth, cur_depth + 1 + (node->right ? height[node->right->val] : -1)));
            dfs2(node->right, cur_depth + 1, max(max_depth, cur_depth + 1 + (node->left ? height[node->left->val] : -1)));
        };

        dfs2(root, 0, 0);

        vector<int> ans;
        for (auto q : queries) {
            ans.push_back(depth[q]);
        }

        return ans;
    }
};
// 1403 ms
// 378.78 MB

