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
  TreeNode* sortedListToBST(ListNode* head) {
    if (!head)
      return nullptr;

    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* prev = nullptr;

    while (fast && fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    if (prev) {
      prev->next = nullptr;
    }

    ListNode* next = slow->next;
    slow->next = nullptr;

    TreeNode* node = new TreeNode(slow->val);

    if (slow == fast) {
      return node;
    }

    node->left = sortedListToBST(head);
    node->right = sortedListToBST(next);

    return node;
  }
};  // 20ms

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
  TreeNode* sortedListToBST(ListNode* head) {
    if (!head)
      return nullptr;

    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* prev = nullptr;

    while (fast && fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    if (prev) {
      prev->next = nullptr;
    }

    TreeNode* node = new TreeNode(slow->val);

    if (slow == fast) {
      return node;
    }

    node->left = sortedListToBST(head);
    node->right = sortedListToBST(slow->next);

    return node;
  }
};  // 28ms