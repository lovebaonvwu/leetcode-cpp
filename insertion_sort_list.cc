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
  ListNode* insertionSortList(ListNode* head) {
    ListNode* ans = nullptr;

    while (head) {
      ListNode* tmp = head;
      head = head->next;

      tmp->next = nullptr;

      if (!ans) {
        ans = tmp;
        continue;
      }

      ListNode* prev = ans;

      if (tmp->val <= prev->val) {
        tmp->next = prev;
        ans = tmp;
      } else {
        while (prev->next) {
          if (prev->next->val > tmp->val) {
            tmp->next = prev->next;
            prev->next = tmp;
            tmp = nullptr;
            break;
          }

          prev = prev->next;
        }

        if (tmp) {
          prev->next = tmp;
        }
      }
    }

    return ans;
  }
};  // 48ms

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
  ListNode* insertionSortList(ListNode* head) {
    ListNode* fakeHead = new ListNode(0);
    ListNode* h = fakeHead;

    while (head) {
      while (h->next && h->next->val < head->val) {
        h = h->next;
      }

      ListNode* tmp = head;
      head = head->next;
      tmp->next = h->next;
      h->next = tmp;

      h = fakeHead;
    }

    return h->next;
  }
};  // 52ms

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
  ListNode* insertionSortList(ListNode* head) {
    ListNode node(INT_MIN);

    ListNode* h = &node;

    while (head) {
      while (h->next && h->next->val < head->val) {
        h = h->next;
      }

      ListNode* tmp = head;
      head = head->next;
      tmp->next = h->next;
      h->next = tmp;

      h = &node;
    }

    return h->next;
  }
};  // 60ms