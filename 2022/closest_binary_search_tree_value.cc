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
    int ans;
    double diff = INT_MAX;
public:
    int closestValue(TreeNode* root, double target) 
    {
        dfs(root, target);

        return ans;
    }

    void dfs(TreeNode* root, double target)
    {
        if (!root)
        {
            return;
        }

        if (abs(root->val - target) < diff)
        {
            diff = abs(root->val - target);
            ans = root->val;
        }

        if (root->val > target)
        {
            dfs(root->left, target);
        }

        if (root->val < target)
        {
            dfs(root->right, target);
        }
    }
};
// Runtime 7 ms
// Memory 20.8 MB
// 2022.12.15 at 奥盛大厦