/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode* tailA;
    ListNode* headB;

    ListNode* cur = list1;
    ListNode* prev = nullptr;
    while (cur) {
      if (cur->val == a) {
        if (prev) {
          tailA = prev;
        }
      }

      if (cur->val == b) {
        headB = cur->next;
      }

      if (prev && prev->val == b) {
        prev->next = nullptr;
      }

      prev = cur;
      cur = cur->next;
    }

    ListNode* tailList2;
    cur = list2;
    while (cur) {
      tailList2 = cur;
      cur = cur->next;
    }

    tailA->next = list2;
    tailList2->next = headB;

    return list1;
  }
};
// Runtime: 432 ms, faster than 16.67%
// Memory Usage: 94.8 MB, less than 100.00%

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode* p = list1;
    while (p->val < a - 1) {
      p = p->next;
    }

    ListNode* q = p;
    while (q->val < b) {
      q = q->next;
    }

    p->next = list2;
    while (p->next) {
      p = p->next;
    }

    p->next = q->next;
    q->next = nullptr;

    return list1;
  }
};
// Runtime: 424 ms, faster than 16.67%
// Memory Usage: 94.8 MB, less than 100.00%