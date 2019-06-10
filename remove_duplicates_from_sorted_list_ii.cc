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
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head)
      return head;

    ListNode* prev = NULL;
    ListNode* cur = head;

    bool dup = false;

    while (cur->next) {
      if (cur->val != cur->next->val) {
        if (!dup) {
          if (!prev) {
            head = cur;
          }
          prev = cur;
        }

        if (prev) {
          prev->next = cur->next;
        }

        dup = false;
      } else if (cur->val == cur->next->val) {
        dup = true;
      }

      cur = cur->next;
    }

    if (dup && prev) {
      prev->next = cur->next;
    } else if (!prev && !dup) {
      head = cur;
    } else if (!prev && dup) {
      head = nullptr;
    }

    return head;
  }
};  // 4ms