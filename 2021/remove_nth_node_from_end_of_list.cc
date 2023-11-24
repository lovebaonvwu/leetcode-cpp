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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* fast = head;
    ListNode* slow = head;

    for (int i = 0; i < n; ++i) {
      fast = fast->next;
    }

    if (!fast) {
      return head->next;
    }

    while (fast->next) {
      fast = fast->next;
      slow = slow->next;
    }

    slow->next = slow->next->next;

    return head;
  }
};  // 8ms

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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    int cnt = 0;
    ListNode* cur = head;

    while (cur) {
      ++cnt;
      cur = cur->next;
    }

    if (n == cnt) {
      return head->next;
    }

    cur = head;
    for (int i = 0; i < cnt - n - 1; ++i) {
      cur = cur->next;
    }

    cur->next = cur->next->next;

    return head;
  }
};  // 4ms