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
  ListNode* sortList(ListNode* head) {
    if (!head || !head->next) {
      return head;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;

    while (fast && fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    prev->next = nullptr;

    ListNode* left = sortList(head);
    ListNode* right = sortList(slow);

    return mergeList(left, right);
  }

  ListNode* mergeList(ListNode* left, ListNode* right) {
    ListNode* head = nullptr;
    ListNode* cur = head;

    while (left && right) {
      ListNode* node = nullptr;

      if (left->val < right->val) {
        node = left;
        left = left->next;
      } else {
        node = right;
        right = right->next;
      }

      if (!head) {
        head = node;
        cur = head;
      } else {
        cur->next = node;
        cur = cur->next;
      }
    }

    while (left) {
      cur->next = left;
      left = left->next;

      cur = cur->next;
    }

    while (right) {
      cur->next = right;
      right = right->next;

      cur = cur->next;
    }

    return head;
  }
};  // 40ms