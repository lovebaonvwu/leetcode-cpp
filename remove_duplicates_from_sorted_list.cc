/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head)
      return head;

    ListNode* prev = head;
    ListNode* cur = head->next;

    while (cur) {
      if (cur->val != prev->val) {
        prev->next = cur;
        prev = prev->next;
      }

      cur = cur->next;
    }

    prev->next = cur;

    return head;
  }
};  // 12ms