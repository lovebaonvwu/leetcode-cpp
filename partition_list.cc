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
  ListNode* partition(ListNode* head, int x) {
    ListNode* l = new ListNode(0);
    ListNode* g = new ListNode(0);

    ListNode* lcur = l;
    ListNode* gcur = g;

    while (head) {
      if (head->val < x) {
        lcur->next = head;
        lcur = lcur->next;
      } else {
        gcur->next = head;
        gcur = gcur->next;
      }

      head = head->next;
    }

    gcur->next = nullptr;
    lcur->next = g->next;

    return l->next;
  }
};  // 4ms