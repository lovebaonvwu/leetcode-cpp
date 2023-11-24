/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
  bool isSubPath(ListNode* head, TreeNode* root) {
    if (!head) {
      return true;
    }

    if (!root) {
      return false;
    }

    return dfs(head, root) || isSubPath(head, root->left) ||
           isSubPath(head, root->right);
  }

  bool dfs(ListNode* head, TreeNode* root) {
    if (!head) {
      return true;
    }

    if (!root) {
      return false;
    }

    return head->val == root->val &&
           (dfs(head->next, root->left) || dfs(head->next, root->right));
  }
};
// Runtime: 40 ms, faster than 93.26%
// Memory Usage: 32.3 MB, less than 5.03%