/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
public:
    bool checkEquivalence(Node* root1, Node* root2) 
    {
        int node1[26] = {0};
        int node2[26] = {0};

        dfs(root1, node1);
        dfs(root2, node2);

        int i = 0;
        for (; i < 26; ++i)
        {
            if (node1[i] != node2[i])
            {
                break;
            }
        }

        return i == 26;
    }

    void dfs(Node* root, int* node)
    {
        if (!root)
        {
            return;
        }

        if (root->val != '+')
        {
            ++node[root->val - 'a'];
        }

        dfs(root->left, node);
        dfs(root->right, node);
    }
};
// Runtime 354 ms
// Memory 39.6 MB
// 2022.12.13 at 奥盛大厦