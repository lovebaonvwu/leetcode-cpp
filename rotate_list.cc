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
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head || k == 0)
      return head;

    ListNode* tail;
    ListNode* cur;
    ListNode* ans;

    int len = 0;

    cur = head;

    while (cur) {
      ++len;

      tail = cur;
      cur = cur->next;
    }

    if (k % len == 0)
      return head;

    len -= (k % len);

    cur = head;

    while (len > 1) {
      cur = cur->next;
      --len;
    }

    ans = cur->next;
    cur->next = NULL;
    tail->next = head;

    return ans;
  }
};