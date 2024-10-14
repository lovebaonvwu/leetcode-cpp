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
    vector<int> cnt;
    int dfs(TreeNode* root) {
        if (!root) {
            return -1;
        }

        if (!root->left && !root->right) {
            cnt.push_back(1);
            return 1;
        }

        int left = dfs(root->left);
        int right = dfs(root->right);

        if (left == right) {
            cnt.push_back(1 + left + right);
            return 1 + left + right;
        }

        return -1;
    }
public:
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        dfs(root);

        sort(rbegin(cnt), rend(cnt));

        return cnt.size() >= k ? cnt[k - 1] : -1;
    }
};
// 71 ms
// 66.52 MB

