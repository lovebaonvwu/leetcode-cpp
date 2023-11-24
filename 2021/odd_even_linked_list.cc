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
  ListNode* oddEvenList(ListNode* head) {
    if (!head)
      return head;

    ListNode* odd;
    ListNode* even;
    ListNode* evenHead;

    evenHead = head->next;

    odd = head;
    even = evenHead;

    while (odd->next && even->next) {
      odd->next = even->next;
      odd = odd->next;

      even->next = odd->next;
      even = even->next;
    }

    odd->next = evenHead;

    return head;
  }
};  // 16ms