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
  ListNode* reverseList(ListNode* head) { return reverseList(head, NULL); }

  ListNode* reverseList(ListNode* head, ListNode* prev) {
    if (!head)
      return prev;

    ListNode* next = head->next;

    head->next = prev;

    return reverseList(next, head);
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
class Solution {
 public:
  ListNode* reverseList(ListNode* head) { return reverse(head, NULL); }

  ListNode* reverse(ListNode* head, ListNode* prev) {
    if (!head)
      return prev;

    ListNode* next = head->next;

    head->next = prev;

    return reverse(next, head);
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
  ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* cur = head;
    ListNode* next;

    while (cur) {
      next = cur->next;
      cur->next = prev;

      prev = cur;
      cur = next;
    }

    return prev;
  }
};  // 12ms

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
  ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* cur = head;

    while (cur) {
      ListNode* next;
      next = cur->next;
      cur->next = prev;

      prev = cur;
      cur = next;
    }

    return prev;
  }
};  // 8ms