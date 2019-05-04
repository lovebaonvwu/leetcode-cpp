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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode* head = NULL;
    ListNode* cur = head;

    while (l1 || l2 || carry) {
      int t1 = l1 ? l1->val : 0;
      int t2 = l2 ? l2->val : 0;

      int sum = t1 + t2 + carry;
      carry = sum / 10;

      ListNode* node;
      if (l1) {
        l1->val = sum % 10;
        node = l1;
      } else if (l2) {
        l2->val = sum % 10;
        node = l2;
      } else {
        node = new ListNode(sum % 10);
      }

      if (!head) {
        head = node;
      } else {
        cur->next = node;
      }

      cur = node;

      l1 = l1 ? l1->next : NULL;
      l2 = l2 ? l2->next : NULL;
    }

    return head;
  }
};