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
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* prev = nullptr;

    ListNode* cur = head;

    while (cur) {
      if (cur->val == val) {
        if (prev) {
          prev->next = cur->next;
        } else {
          head = cur->next;
        }
      } else {
        prev = cur;
      }

      cur = cur->next;
    }

    return head;
  }
};  // 28ms

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
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* prev = nullptr;

    ListNode* cur = head;

    while (cur) {
      if (cur->val == val) {
        if (prev) {
          ListNode* tmp = cur;
          prev->next = cur->next;
          cur = cur->next;

          delete tmp;
        } else {
          ListNode* tmp = head;
          head = cur->next;
          cur = cur->next;

          delete tmp;
        }
      } else {
        prev = cur;
        cur = cur->next;
      }
    }

    return head;
  }
};  // 36ms