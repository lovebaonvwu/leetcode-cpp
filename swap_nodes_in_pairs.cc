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
  ListNode* swapPairs(ListNode* head) { return dfs(head); }

  ListNode* dfs(ListNode* head) {
    if (!head || !head->next) {
      return head;
    }

    if (!head->next->next) {
      ListNode* next = head->next;

      next->next = head;
      head->next = nullptr;

      return next;
    }

    ListNode* tail = dfs(head->next->next);

    ListNode* next = head->next;
    head->next = tail;

    next->next = head;

    return next;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.5 MB, less than 100.00%

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
  ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) {
      return head;
    }

    ListNode* cur = head;
    head = head->next;

    ListNode* prev = nullptr;

    while (cur && cur->next) {
      if (prev) {
        prev->next = cur->next;
      }

      prev = cur;

      ListNode* tmp = cur->next->next;

      cur->next->next = cur;
      cur->next = tmp;

      cur = tmp;
    }

    return head;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.6 MB, less than 96.43%